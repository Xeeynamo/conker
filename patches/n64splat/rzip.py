import os
from segtypes.segment import N64Segment
from pathlib import Path

import rareunzip

# Rare zip format:
# 4 byte uncompressed length followed by gzip level 9 stripped payload
class N64SegRzip(N64Segment):
    def __init__(self, rom_start, rom_end, segtype, name, ram_addr, files, options):
        super().__init__(rom_start, rom_end, segtype, name, ram_addr, files, options)
        self.padded_files = set()

    def split(self, rom_bytes, base_path):
        out_dir = self.create_split_dir(base_path, "rzip")
        print("Splitting rzip %s" % self.name)

        # still write out bin
        with open(os.path.join(out_dir,  self.name + ".bin"), "wb") as f:
            f.write(rom_bytes[self.rom_start : self.rom_end])

        for i, split_file in enumerate(self.files):
            filename = str(i).zfill(4) # "{0:#0{1}x}".format(split_file["start"], 10)
            compressed = rom_bytes[split_file["start"] : split_file["end"]]
            padding = 0
            decompressed = None
            try:
                decompressed = rareunzip.runzip(compressed)
            except:
                # 1 byte of padding seems to be enough
                padding = 3
                while padding > 0:
                    try:
                        decompressed = rareunzip.runzip(compressed[:-padding])
                        compressed = compressed[:-padding]
                        break
                    except:
                        padding -= 1
                        if padding == 0:
                            print("Error decompressing %s" % filename)
                            continue
                # save down padding
                with open(os.path.join(out_dir,  filename + ".pad"), "wb") as f:
                    if padding > 1:
                        print("padding %i for %s" % (padding, str(hex(split_file["start"]))))
                    f.write(compressed[-padding:])
                self.padded_files.add(split_file["start"])
            with open(os.path.join(out_dir,  filename + ".gz"), "wb") as f:
                f.write(compressed)
            if decompressed:
                with open(os.path.join(out_dir,  filename + ".bin"), "wb") as f:
                    f.write(decompressed)

    def get_ld_section(self):
        section_name = ".data_{}".format(self.name)

        lines = []
        lines.append("    /* 0x00000000 {:X}-{:X} [{:X}] */".format(self.rom_start, self.rom_end, self.rom_end - self.rom_start))
        lines.append("    {} 0x{:X} : AT(0x{:X}) ".format(section_name, self.rom_start, self.rom_start) + "{")
        lines.append("        build/rzip/{}.o(.data);".format(self.name))
        lines.append("    }")
        lines.append("")
        lines.append("")
        return "\n".join(lines)


    @staticmethod
    def create_makefile_target():
        return ""
