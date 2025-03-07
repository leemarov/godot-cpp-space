/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

//#include "example.h"
#include "smooth.h"
#include "smooth_2d.h"
#include "uuid_v4.h"

using namespace godot;

void initialize_space_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	// ClassDB::register_class<ExampleRef>();
// 	ClassDB::register_class<ExampleMin>();
//	ClassDB::register_class<Example>();
//	ClassDB::register_class<ExampleVirtual>(true);
	// ClassDB::register_abstract_class<ExampleAbstract>();

	ClassDB::register_class<Smooth>();
	ClassDB::register_class<Smooth2D>();

	ClassDB::register_class<UUIDv4>();
}

void uninitialize_space_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT space_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_space_module);
	init_obj.register_terminator(uninitialize_space_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
