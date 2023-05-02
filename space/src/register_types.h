/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef SPACE_REGISTER_TYPES_H
#define SPACE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_space_module(ModuleInitializationLevel p_level);
void uninitialize_space_module(ModuleInitializationLevel p_level);

#endif // SPACE_REGISTER_TYPES_H
