import re
import sys
import os

def process_lines(lines):
    output = []

    for line in lines:
        line = line.rstrip()

        # TYPEDEF
        m = re.match(r'^TYPEDEF\s+(.*)\s+([^ ]+);$', line)
        if m:
            type_def, name = m.groups()
            output.append(f"#if defined(__NEED_{name}) && !defined(__DEFINED_{name})")
            output.append(f"typedef {type_def} {name};")
            output.append(f"#define __DEFINED_{name}")
            output.append("#endif\n")
            continue

        # STRUCT
        m = re.match(r'^STRUCT\s+([^ ]+)\s+(.*);$', line)
        if m:
            name, body = m.groups()
            output.append(f"#if defined(__NEED_struct_{name}) && !defined(__DEFINED_struct_{name})")
            output.append(f"struct {name} {body};")
            output.append(f"#define __DEFINED_struct_{name}")
            output.append("#endif\n")
            continue

        # UNION
        m = re.match(r'^UNION\s+([^ ]+)\s+(.*);$', line)
        if m:
            name, body = m.groups()
            output.append(f"#if defined(__NEED_union_{name}) && !defined(__DEFINED_union_{name})")
            output.append(f"union {name} {body};")
            output.append(f"#define __DEFINED_union_{name}")
            output.append("#endif\n")
            continue

        # 默认原样输出
        output.append(line)

    return '\n'.join(output)

if __name__ == "__main__":
    # iterate all files in the input directory
    for arch in ['aarch64', 'arm', 'x32', 'x86_64', 'i386']:
        print(f"Processing architecture: {arch}")
        file_1 = os.path.join('musl/arch', arch, 'bits', 'alltypes.h.in')
        file_2 = 'musl/include/alltypes.h.in'

        all_lines = []
        for filename in [file_1, file_2]:
            with open(filename, 'r') as f:
                all_lines.extend(f.readlines())

        result = process_lines(all_lines)
        
        os.makedirs(f'include/linux/bits/{arch}', exist_ok=True)
        with open(f'include/linux/bits/{arch}/alltypes.h', 'wt', newline='\n') as f:
            f.write(result)
