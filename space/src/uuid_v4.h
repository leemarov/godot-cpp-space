#ifndef UUID_V4_CLASS_H
#define UUID_V4_CLASS_H

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <string>

using namespace godot;

class UUIDv4 : public RefCounted {
	GDCLASS(UUIDv4, RefCounted);

private:
	

public:
	UUIDv4() {};
	~UUIDv4() {};

	String generate() {
		constexpr static char const* const CHARS = 
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		char uuid[37];
		int rnd = godot::UtilityFunctions::randi();

		uuid[8] = '-';
		uuid[13] = '-';
		uuid[18] = '-';
		uuid[23] = '-';

		uuid[14] = '4';
		uuid[36] = 0;

		for(int i=0;i<36;i++){
			if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23 && i != 36) {
				if (rnd <= 0x02) {
					rnd = godot::UtilityFunctions::randi() | 0;
				}
				rnd >>= 4;
				uuid[i] = CHARS[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
			}
		}
		return String(uuid);
	}

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("generate"), &UUIDv4::generate);
	}
};


#endif // UUID_V4_CLASS_H
