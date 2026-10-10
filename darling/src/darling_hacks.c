#include <syslog.h>
#include <stdarg.h>

typedef float __attribute__((ext_vector_type(4))) simd_float4;
typedef struct { simd_float4 columns[4]; } simd_float4x4;

/* The SDK declares this as `extern const simd_float4x4 matrix_identity_float4x4` (simd/matrix.h). It used to be a
 * bare, uninitialised definition under a TODO, i.e. an exported all-zero matrix: every guest that multiplied by
 * the identity got a zeroed result and nothing reported anything. An exported constant may not be a
 * plausible-looking wrong value -- it holds the correct value or it does not exist -- and the qualifier matches
 * the declaration callers compile against. Column-major, matching the struct layout above. */
const simd_float4x4 matrix_identity_float4x4 = {
	.columns = {
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
	}
};
