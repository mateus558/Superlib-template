project('superlib', 'cpp',
  version : '0.1.0',
  default_options : ['warning_level=0', 'cpp_std=c++17'])

libs_names = ['liba', 'libb', 'libc']

prefix = get_option('prefix')
project_install_dir = get_option('libdir')
build_type = get_option('buildtype')
library_type = get_option('default_library')

project_description = 'Combination of several libraries into one'
project_subdir = 'superlib'
project_headers = ['superlib.hpp']

message('Build type: ' + build_type)
message('Install directory: ' + prefix / project_install_dir)
message('Default library type: ' + library_type)

combined = []
project_dependencies = []
foreach lib_name : libs_names
  lib = subproject(lib_name)
  lib_name = '_'.join(lib_name.split('-'))
  combined += lib.get_variable(lib_name+'_tgt').extract_all_objects()
  project_dependencies += lib.get_variable(lib_name+'_dep')
endforeach

subdir('docs')
install_headers(project_headers, subdir: project_subdir)

project_target = library(meson.project_name(), [],
  dependencies: project_dependencies,
  objects: combined,
  install : true,
  install_dir : project_install_dir,
  version: meson.project_version(),
  soversion: '0'
)

project_target_dep = declare_dependency(
  link_with : project_target,
  include_directories : include_directories('.'),
  dependencies: project_dependencies
)

set_variable(meson.project_name() + '_dep', project_target_dep)
set_variable(meson.project_name() + '_tgt', project_target)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : project_description,
  subdirs : project_subdir
)