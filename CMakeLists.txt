idf_component_register(SRCS
                "cutils.c" "cutils.h"
                "libbf.c" "libbf.h" 
                "libregexp.c" "libregexp.h" "libregexp-opcode.h"
                "libunicode.c" "libunicode.h" "libunicode-table.h"
                "list.h" 
                "qjs.c" "qjsc.c" "quickjs.c" "quickjs.h" "quickjs-atom.h" 
                "quickjs-libc.c" "quickjs-libc.h" "quickjs-opcode.h"
                "unicode_gen.c" "unicode_gen_def.h"
        INCLUDE_DIRS ".")

target_compile_definitions(${COMPONENT_TARGET} PRIVATE "-DCONFIG_VERSION=\"2020-11-08\"" "-D_GNU_SOURCE")