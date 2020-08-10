idf_component_register(SRCS "hello_world_main.c"
                "bjson.c" 
                "cutils.c" "cutils.h" 
                "jscompress.c" 
                "libbf.c" "libbf.h" 
                "libregexp.c" "libregexp.h" "libregexp-opcode.h"
                "libunicode.c" "libunicode.h" "libunicode-table.h"
                "list.h" 
                "qjs.c" "qjsc.c" "quickjs.c" "quickjs.h" "quickjs-atom.h" 
                "quickjs-libc.c" "quickjs-libc.h" "quickjs-opcode.h"
                "unicode_gen.c" "unicode_gen_def.h"
        INCLUDE_DIRS "")

target_compile_definitions(${COMPONENT_TARGET} PRIVATE "-DCONFIG_VERSION=\"2020-07-05\"" "-D_GNU_SOURCE")