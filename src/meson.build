miok_queue_lib = static_library('miok-queue',
    'package.c',
    include_directories: inc_dir,
    gnu_symbol_visibility: 'hidden',
    install: true)

miok_queue_dep = declare_dependency(
    link_with: miok_queue_lib,
    include_directories: inc_dir)
