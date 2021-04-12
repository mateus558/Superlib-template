project(
  'libb',
  'cpp',
  version : '0.1.0',
  default_options : ['warning_level=3', 'cpp_std=c++17']
)

build_type = get_option('buildtype')
library_type = get_option('default_library')
prefix = get_option('prefix')
install_dir = get_option('libdir')
project_install = true

project_description = 'Library B.'
project_subdir = 'superlib/libb'
project_source_files = ['src/libb.cpp']
project_headers = ['include/libb/libb.hpp']

message('Build type: ' + build_type)
message('Install directory: ' + prefix / install_dir)
message('Include directory: ' + prefix / 'include' / project_subdir)
message('Default library type: ' + library_type)

lib_args = ['-DBUILDING_LIBB']

project_target = library(meson.project_name(), [project_source_files, project_headers],
  install : project_install,
  install_dir : install_dir,
  include_directories : include_directories('include', 'src', '.'),
  version: meson.project_version(),
  soversion: '0',
  cpp_args : lib_args,
  gnu_symbol_visibility : 'default',
)

install_headers(project_headers, subdir : project_subdir)

project_target_dep = declare_dependency(
  include_directories: include_directories('include', 'src', '.'),
  sources: project_headers,
  link_with : project_target,
)

varprefix = '_'.join(meson.project_name().split('-'))
set_variable(varprefix + '_dep', project_target_dep)
set_variable(varprefix + '_tgt', project_target)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : project_description,
  libraries : project_target,
  subdirs : project_subdir,
  version : meson.project_version()
)