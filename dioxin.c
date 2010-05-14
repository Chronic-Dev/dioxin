#include "includes/libdioxin.h"
#include <cstddef>

iDevice::iDevice() {
#ifdef __linux__
	phone = NULL;
	client = NULL;
	ret = IDEVICE_E_UNKNOWN_ERROR;
	ret = idevice_new(&phone, NULL);
	if (ret == IDEVICE_E_SUCCESS) {
		if (lockdownd_client_new_with_handshake(phone, &client, "ideviceenterrecovery") != LOCKDOWN_E_SUCCESS) {
			idevice_free(phone);
		}
	}
#else
	//TODO: Windows and Mac code here!
#endif
}

iDevice::~iDevice() {
	lockdownd_client_free(client);
	idevice_free(phone);
}

int iDevice::enter_recovery() {
#ifdef __linux__
	if (lockdownd_enter_recovery(client) != LOCKDOWN_E_SUCCESS) {
		return -1; //Failed to enter recovery
	}
	return 0; //Success!
#else
#endif
}

