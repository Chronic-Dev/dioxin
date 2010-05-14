#ifndef _DIXION_H_
#define _DIXION_H_
#ifdef __linux__
#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>
#endif

class iDevice {
	public:
		iDevice();
		~iDevice();
		int enter_recovery();
	private:
#ifdef __linux__
		lockdownd_client_t client;
		idevice_t phone;
		idevice_error_t ret;
#else
		//TODO: Windows & Mac stuff here
#endif
};

#endif
