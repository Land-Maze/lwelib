#include <lml/mlwe-fast.h>

int mlwe_fast_kem_keypair(uint8_t* pk, uint8_t* sk) {
	if (pk == NULL || sk == NULL) {
		return MLWE_FAST_ERROR_GENERIC;
	}

	for (size_t i = 0; i < MLWE_FAST_PUBLICKEYBYTES; i++) {
		pk[i] = (uint8_t)(0xFF);
	}
	for (size_t i = 0; i < MLWE_FAST_SECRETKEYBYTES; i++) {
		sk[i] = (uint8_t)(0xFF);
	}

	return MLWE_FAST_ERROR_NONE;
}

int mlwe_fast_kem_encaps(uint8_t* ct, uint8_t* ss, const uint8_t* pk) {
	if (ct == NULL || ss == NULL || pk == NULL) {
		return MLWE_FAST_ERROR_GENERIC;
	}

	for (size_t i = 0; i < MLWE_FAST_CIPHERTEXTBYTES; i++) {
		ct[i] = (uint8_t)(0xFF);
	}
	for (size_t i = 0; i < MLWE_FAST_SSBYTES; i++) {
		ss[i] = (uint8_t)(0xFF);
	}

	return MLWE_FAST_ERROR_NONE;
}

int mlwe_fast_kem_decaps(uint8_t* ss, const uint8_t* ct, const uint8_t* sk) {
	if (ss == NULL || ct == NULL || sk == NULL) {
		return MLWE_FAST_ERROR_GENERIC;
	}

	for (size_t i = 0; i < MLWE_FAST_SSBYTES; i++) {
		ss[i] = (uint8_t)(0xFF);
	}

	return MLWE_FAST_ERROR_NONE;
}