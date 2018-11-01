// Part of Measurement Kit <https://measurement-kit.github.io/>.
// Measurement Kit is free software under the BSD license. See AUTHORS
// and LICENSE for more information on the copying conditions.
#ifndef MEASUREMENT_KIT_MKORCHESTRA_H
#define MEASUREMENT_KIT_MKORCHESTRA_H

#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

/// mkorchestra_metadata_t contains client metadata.
typedef struct mkorchestra_metadata mkorchestra_metadata_t;

/// mkorchestra_metadata_new_nonnull creates a client metadata
/// instance. It always returns a valid pointer and aborts if allocating
/// the new metadata instance fails.
mkorchestra_metadata_t *mkorchestra_metadata_new_nonnull(void);

/// mkorchestra_metadata_set_available_bandwidth sets the
/// bandwidth available to the client. This function aborts if it
/// is passed any null pointer argument.
void mkorchestra_metadata_set_available_bandwidth(
    mkorchestra_metadata_t *metadata,
    const char *available_bandwidth);

/// mkorchestra_metadata_set_device_token sets the device token. This
/// function aborts if passed any null pointer argument.
void mkorchestra_metadata_set_device_token(
    mkorchestra_metadata_t *metadata,
    const char *device_token);

/// mkorchestra_metadata_set_language sets the language. This function
/// aborts if passed any null pointer argument.
void mkorchestra_metadata_set_language(
    mkorchestra_metadata_t *metadata,
    const char *language);

/// mkorchestra_metadata_set_network_type sets the network_type. This
/// function aborts if passed any null pointer argument.
void mkorchestra_metadata_set_network_type(
    mkorchestra_metadata_t *metadata,
    const char *network_type);

/// mkorchestra_metadata_set_platform sets the platform. This function
/// aborts if passed any null pointer argument.
void mkorchestra_metadata_set_platform(
    mkorchestra_metadata_t *metadata,
    const char *platform);

/// mkorchestra_metadata_set_probe_asn sets the probe_asn. This
/// function aborts if passed any null pointer argument.
void mkorchestra_metadata_set_probe_asn(
    mkorchestra_metadata_t *metadata,
    const char *probe_asn);

/// mkorchestra_metadata_set_probe_cc sets the probe_cc. This
/// function aborts if passed any null pointer argument.
void mkorchestra_metadata_set_probe_cc(
    mkorchestra_metadata_t *metadata,
    const char *probe_cc);

/// mkorchestra_metadata_set_probe_family sets the probe_family. This
/// function aborts if passed any null pointer argument.
void mkorchestra_metadata_set_probe_family(
    mkorchestra_metadata_t *metadata,
    const char *probe_family);

/// mkorchestra_metadata_set_probe_timezone sets the probe_timezone. It
/// aborts if passed any null pointer argument.
void mkorchestra_metadata_set_probe_timezone(
    mkorchestra_metadata_t *metadata,
    const char *probe_timezone);

/// mkorchestra_metadata_set_software_name sets the software_name. This
/// function aborts if passed any null pointer argument.
void mkorchestra_metadata_set_software_name(
    mkorchestra_metadata_t *metadata,
    const char *software_name);

/// mkorchestra_metadata_set_software_version sets the software_version.
/// It aborts if passed any null pointer argument.
void mkorchestra_metadata_set_software_version(
    mkorchestra_metadata_t *metadata,
    const char *software_version);

/// mkorchestra_metadata_add_supported_test adds @p supported_test
/// to the list of tests supported by this probe. This function aborts
/// when passed any null pointer argument.
void mkorchestra_metadata_add_supported_test(
    mkorchestra_metadata_t *metadata,
    const char *supported_test);

/// mkorchestra_metadata_delete destroys @p metadata. Note that
/// @p metadata MAY be null.
void mkorchestra_metadata_delete(
    mkorchestra_metadata_t *metadata);

/// mkorchestra_register_request_t is a request to the register API.
typedef struct mkorchestra_register_request mkorchestra_register_request_t;

/// mkorchestra_register_response_t is a response to the register API.
typedef struct mkorchestra_register_response mkorchestra_register_response_t;

/// mkorchestra_register_request_new_nonnull creates a new register request. It
/// always returns a valid pointer. It aborts if allocation fails.
mkorchestra_register_request_t *mkorchestra_register_request_new_nonnull(void);

/// mkorchestra_register_request_set_password sets @p password as
/// the password to be used to identify this probe. This function aborts
/// if passed any null pointer argument.
void mkorchestra_register_request_set_password(
    mkorchestra_register_request_t *request,
    const char *password);

/// mkorchestra_register_request_set_metadata copies @p metadata
/// as the metadata associated with the register request. This function
/// aborts if passed any null pointer argument.
void mkorchestra_register_request_set_metadata(
    mkorchestra_register_request_t *request,
    const mkorchestra_metadata_t *metadata);

/// mkorchestra_register_request_set_base_url sets the base URL for
/// the @p request. It aborts if passed any null pointer.
void mkorchestra_register_request_set_base_url(
    mkorchestra_register_request_t *request,
    const char *base_url);

/// mkorchestra_register_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_register_request_set_ca_bundle_path(
    mkorchestra_register_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_register_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_register_request_set_timeout(
    mkorchestra_register_request_t *request,
    int64_t timeout);

/// mkorchestra_register_request_perform_nonnull performs @p request. It will
/// always return a valid pointer. It aborts if any malloc fails.
mkorchestra_register_response_t *mkorchestra_register_request_perform_nonnull(
    const mkorchestra_register_request_t *request);

/// mkorchestra_register_request_delete destroys @p request. Note that
/// @p request MAY be a null pointer.
void mkorchestra_register_request_delete(
    mkorchestra_register_request_t *request);

/// mkorchestra_register_response_good returns true if we received a response
/// from the API and such response indicated success, false otherwise. It
/// calls abort if @p response is a null pointer.
int64_t mkorchestra_register_response_good(
    const mkorchestra_register_response_t *response);

/// mkorchestra_register_response_get_client_id returns the client ID as
/// parsed by mkorchestra_register_response_parse. It always returns a valid
/// string owned by @p response. It aborts if passed null arguments.
const char *mkorchestra_register_response_get_client_id(
    const mkorchestra_register_response_t *response);

/// mkorchestra_register_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_register_response_get_binary_logs(
    const mkorchestra_register_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_register_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_register_response_delete(
    mkorchestra_register_response_t *response);

/// mkorchestra_login_request_t is a request to the login API.
typedef struct mkorchestra_login_request mkorchestra_login_request_t;

/// mkorchestra_login_response_t is a response from the login API.
typedef struct mkorchestra_login_response mkorchestra_login_response_t;

/// mkorchestra_login_request_new_nonnull creates a new login request. It will
/// always return a valid pointer and will abort if out of memory.
mkorchestra_login_request_t *mkorchestra_login_request_new_nonnull(void);

/// mkorchestra_login_request_set_username sets the login request username. It
/// will abort if passed any null pointer argument.
void mkorchestra_login_request_set_username(
    mkorchestra_login_request_t *request,
    const char *username);

/// mkorchestra_login_request_set_password sets the login request password. It
/// will abort if passed any null pointer argument.
void mkorchestra_login_request_set_password(
    mkorchestra_login_request_t *request,
    const char *password);

/// mkorchestra_login_request_set_base_url sets the base URL for
/// the @p request. It will abort if passed null pointers.
void mkorchestra_login_request_set_base_url(
    mkorchestra_login_request_t *request,
    const char *base_url);

/// mkorchestra_login_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_login_request_set_ca_bundle_path(
    mkorchestra_login_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_login_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_login_request_set_timeout(
    mkorchestra_login_request_t *request,
    int64_t timeout);

/// mkorchestra_login_request_perform_nonnull performs @p request. It will
/// always return a valid pointer. It aborts if passed a null @p request.
mkorchestra_login_response_t *mkorchestra_login_request_perform_nonnull(
    const mkorchestra_login_request_t *request);

/// mkorchestra_login_request_delete destroys @p request. Note that @p
/// request MAY be a null pointer.
void mkorchestra_login_request_delete(mkorchestra_login_request_t *request);

/// mkorchestra_login_response_good returns true if we received a response
/// from the API and that response is successful, false otherwise. It
/// calls abort if passed a null pointer argument.
int64_t mkorchestra_login_response_good(
    const mkorchestra_login_response_t *response);

/// mkorchestra_login_response_get_expire returns when the authentication
/// token will expire. It always returns a valid string owned by @p response,
/// which MAY be an empty string if the request failed. This function will
/// call abort if passed a null pointer.
const char *mkorchestra_login_response_get_expire(
    const mkorchestra_login_response_t *response);

/// mkorchestra_login_response_get_token returns the authentication token. It
/// always returns a valid string owned by @p response, which MAY be an empty
/// string if the request failed. It aborts if passed a null pointer.
const char *mkorchestra_login_response_get_token(
    const mkorchestra_login_response_t *response);

/// mkorchestra_login_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_login_response_get_binary_logs(
    const mkorchestra_login_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_login_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_login_response_delete(
    mkorchestra_login_response_t *response);

/// mkorchestra_update_request_t is a request to the update API.
typedef struct mkorchestra_update_request mkorchestra_update_request_t;

/// mkorchestra_update_response_t is a response to the update API.
typedef struct mkorchestra_update_response mkorchestra_update_response_t;

/// mkorchestra_update_request_new_nonnull creates a new update request. It
/// always returns a valid pointer. It aborts if allocation fails.
mkorchestra_update_request_t *mkorchestra_update_request_new_nonnull(void);

/// mkorchestra_update_request_set_token sets @p token as the token to be used
/// to identify this probe. This function aborts if passed any null rgument.
void mkorchestra_update_request_set_token(
    mkorchestra_update_request_t *request,
    const char *token);

/// mkorchestra_update_request_client_id sets @p client_id as the ID to be used
/// to identify this probe. This function aborts if passed any null rgument.
void mkorchestra_update_request_set_client_id(
    mkorchestra_update_request_t *request,
    const char *client_id);

/// mkorchestra_update_request_set_metadata copies @p metadata
/// as the metadata associated with the update request. This function
/// aborts if passed any null pointer argument.
void mkorchestra_update_request_set_metadata(
    mkorchestra_update_request_t *request,
    const mkorchestra_metadata_t *metadata);

/// mkorchestra_update_request_set_base_url sets the base URL for
/// the @p request. It aborts if passed any null pointer.
void mkorchestra_update_request_set_base_url(
    mkorchestra_update_request_t *request,
    const char *base_url);

/// mkorchestra_update_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_update_request_set_ca_bundle_path(
    mkorchestra_update_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_update_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_update_request_set_timeout(
    mkorchestra_update_request_t *request,
    int64_t timeout);

/// mkorchestra_update_request_perform_nonnull performs @p request. It will
/// always return a valid pointer. It aborts if any malloc fails.
mkorchestra_update_response_t *mkorchestra_update_request_perform_nonnull(
    const mkorchestra_update_request_t *request);

/// mkorchestra_update_request_delete destroys @p request. Note that
/// @p request MAY be a null pointer.
void mkorchestra_update_request_delete(
    mkorchestra_update_request_t *request);

/// mkorchestra_update_response_good returns true if we received a response
/// from the API and such response indicated success, false otherwise. It
/// calls abort if @p response is a null pointer.
int64_t mkorchestra_update_response_good(
    const mkorchestra_update_response_t *response);

/// mkorchestra_update_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_update_response_get_binary_logs(
    const mkorchestra_update_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_update_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_update_response_delete(
    mkorchestra_update_response_t *response);

/// mkorchestra_collectors_request_t is a request for the collectors API.
typedef struct mkorchestra_collectors_request mkorchestra_collectors_request_t;

/// mkorchestra_collectors_response_t is a response for the collectors API.
typedef struct mkorchestra_collectors_response mkorchestra_collectors_response_t;

/// mkorchestra_collectors_request_new_nonnull creates a new request for the
/// collectors endpoint. The returned pointer is always valid. This function
/// calls abort if allocating new memory fails.
mkorchestra_collectors_request_t *
mkorchestra_collectors_request_new_nonnull(void);

/// mkorchestra_collectors_request_set_base_url sets the base URL for
/// the @p request. It aborts if passed any null pointer.
void mkorchestra_collectors_request_set_base_url(
    mkorchestra_collectors_request_t *request,
    const char *base_url);

/// mkorchestra_collectors_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_collectors_request_set_ca_bundle_path(
    mkorchestra_collectors_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_collectors_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_collectors_request_set_timeout(
    mkorchestra_collectors_request_t *request,
    int64_t timeout);

/// mkorchestra_collectors_request_perform_nonnull performs @p request. It
/// always returns a valid pointer. It aborts if allocation fails.
mkorchestra_collectors_response_t *
mkorchestra_collectors_request_perform_nonnull(
    const mkorchestra_collectors_request_t *request);

/// mkorchestra_collectors_request_delete destroys @p request. Note that
/// @p request MAY be a null pointer.
void mkorchestra_collectors_request_delete(
    mkorchestra_collectors_request_t *request);

/// mkorchestra_collectors_response_good returns true if we received a response
/// from the API and such response indicated success, false otherwise. It
/// calls abort if @p response is a null pointer.
int64_t mkorchestra_collectors_response_good(
    const mkorchestra_collectors_response_t *response);

/// mkorchestra_collectors_response_get_https_collectors_size returns the
/// number of available https collectors. This function aborts if passed
/// a null pointer @p response.
size_t mkorchestra_collectors_response_get_https_collectors_size(
    const mkorchestra_collectors_response_t *response);

/// mkorchestra_collectors_response_get_https_collector_at returns the https
/// collector at index @p idx. If there is no collector for such index, this
/// function returns the empty string. The returned string is owned by the @p
/// response instance. This function aborts if passed a null @p response.
const char *mkorchestra_collectors_response_get_https_collector_at(
    const mkorchestra_collectors_response_t *response, size_t idx);

/// mkorchestra_collectors_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_collectors_response_get_binary_logs(
    const mkorchestra_collectors_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_collectors_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_collectors_response_delete(
    mkorchestra_collectors_response_t *response);

/// mkorchestra_ths_request_t is a request for the test-helpers API.
typedef struct mkorchestra_ths_request mkorchestra_ths_request_t;

/// mkorchestra_ths_response_t is a response for the test-helpers API.
typedef struct mkorchestra_ths_response mkorchestra_ths_response_t;

/// mkorchestra_ths_request_new_nonnull creates a new request for the
/// test-helpers endpoint. The returned pointer is always valid. This function
/// calls abort if allocating new memory fails.
mkorchestra_ths_request_t *
mkorchestra_ths_request_new_nonnull(void);

/// mkorchestra_ths_request_set_base_url sets the base URL for
/// the @p request. It aborts if passed any null pointer.
void mkorchestra_ths_request_set_base_url(
    mkorchestra_ths_request_t *request,
    const char *base_url);

/// mkorchestra_ths_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_ths_request_set_ca_bundle_path(
    mkorchestra_ths_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_ths_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_ths_request_set_timeout(
    mkorchestra_ths_request_t *request,
    int64_t timeout);

/// mkorchestra_ths_request_perform_nonnull performs @p request. It
/// always returns a valid pointer. It aborts if allocation fails.
mkorchestra_ths_response_t *
mkorchestra_ths_request_perform_nonnull(
    const mkorchestra_ths_request_t *request);

/// mkorchestra_ths_request_delete destroys @p request. Note that
/// @p request MAY be a null pointer.
void mkorchestra_ths_request_delete(
    mkorchestra_ths_request_t *request);

/// mkorchestra_ths_response_good returns true if we received a response
/// from the API and such response indicated success, false otherwise. It
/// calls abort if @p response is a null pointer.
int64_t mkorchestra_ths_response_good(
    const mkorchestra_ths_response_t *response);

/// mkorchestra_ths_response_get_wchttpsths_size
/// returns the number of available https Web Connectivity ths. This
/// function aborts if passed a null pointer @p response.
size_t mkorchestra_ths_response_get_wchttpsths_size(
    const mkorchestra_ths_response_t *response);

/// mkorchestra_ths_response_get_wchttpsth_at
/// returns the https Web Connectivity test helper at index @p idx. If there is
/// no helper for such index, this function returns the empty string. The
/// returned string is owned by the @p response instance. This function aborts
/// if passed a null @p response.
const char *mkorchestra_ths_response_get_wchttpsth_at(
    const mkorchestra_ths_response_t *response, size_t idx);

/// mkorchestra_ths_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_ths_response_get_binary_logs(
    const mkorchestra_ths_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_ths_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_ths_response_delete(
    mkorchestra_ths_response_t *response);

#ifdef __cplusplus
}  // extern "C"

#include <memory>
#include <string>

/// mkorchestra_metadata_deleter is a deleter for
/// mkorchestra_metadata_t.
struct mkorchestra_metadata_deleter {
  void operator()(mkorchestra_metadata_t *s) {
    mkorchestra_metadata_delete(s);
  }
};

/// mkorchestra_metadata_uptr is a unique pointer to a
/// mkorchestra_metadata_t instance.
using mkorchestra_metadata_uptr = std::unique_ptr<
    mkorchestra_metadata_t, mkorchestra_metadata_deleter>;

/// mkorchestra_register_request_deleter is a deleter for
/// mkorchestra_register_request_t.
struct mkorchestra_register_request_deleter {
  void operator()(mkorchestra_register_request_t *s) {
    mkorchestra_register_request_delete(s);
  }
};

/// mkorchestra_register_request_uptr is a unique pointer to a
/// mkorchestra_register_request_t instance.
using mkorchestra_register_request_uptr = std::unique_ptr<
    mkorchestra_register_request_t, mkorchestra_register_request_deleter>;

/// mkorchestra_register_response_deleter is a deleter for
/// mkorchestra_register_response_t.
struct mkorchestra_register_response_deleter {
  void operator()(mkorchestra_register_response_t *s) {
    mkorchestra_register_response_delete(s);
  }
};

/// mkorchestra_register_response_uptr is a unique pointer to a
/// mkorchestra_register_response_t instance.
using mkorchestra_register_response_uptr = std::unique_ptr<
    mkorchestra_register_response_t, mkorchestra_register_response_deleter>;

/// mkorchestra_login_request_deleter is a deleter for
/// mkorchestra_login_request_t.
struct mkorchestra_login_request_deleter {
  void operator()(mkorchestra_login_request_t *s) {
    mkorchestra_login_request_delete(s);
  }
};

/// mkorchestra_login_request_uptr is a unique pointer to a
/// mkorchestra_login_request_t instance.
using mkorchestra_login_request_uptr = std::unique_ptr<
    mkorchestra_login_request_t, mkorchestra_login_request_deleter>;

/// mkorchestra_login_response_deleter is a deleter for
/// mkorchestra_login_response_t.
struct mkorchestra_login_response_deleter {
  void operator()(mkorchestra_login_response_t *s) {
    mkorchestra_login_response_delete(s);
  }
};

/// mkorchestra_login_response_uptr is a unique pointer to a
/// mkorchestra_login_response_t instance.
using mkorchestra_login_response_uptr = std::unique_ptr<
    mkorchestra_login_response_t, mkorchestra_login_response_deleter>;

/// mkorchestra_update_request_deleter is a deleter for
/// mkorchestra_update_request_t.
struct mkorchestra_update_request_deleter {
  void operator()(mkorchestra_update_request_t *s) {
    mkorchestra_update_request_delete(s);
  }
};

/// mkorchestra_update_request_uptr is a unique pointer to a
/// mkorchestra_update_request_t instance.
using mkorchestra_update_request_uptr = std::unique_ptr<
    mkorchestra_update_request_t, mkorchestra_update_request_deleter>;

/// mkorchestra_update_response_deleter is a deleter for
/// mkorchestra_update_response_t.
struct mkorchestra_update_response_deleter {
  void operator()(mkorchestra_update_response_t *s) {
    mkorchestra_update_response_delete(s);
  }
};

/// mkorchestra_update_response_uptr is a unique pointer to a
/// mkorchestra_update_response_t instance.
using mkorchestra_update_response_uptr = std::unique_ptr<
    mkorchestra_update_response_t, mkorchestra_update_response_deleter>;

/// mkorchestra_collectors_request_deleter is a deleter for
/// mkorchestra_collectors_request_t.
struct mkorchestra_collectors_request_deleter {
  void operator()(mkorchestra_collectors_request_t *s) {
    mkorchestra_collectors_request_delete(s);
  }
};

/// mkorchestra_collectors_request_uptr is a unique pointer to a
/// mkorchestra_collectors_request_t instance.
using mkorchestra_collectors_request_uptr = std::unique_ptr<
    mkorchestra_collectors_request_t, mkorchestra_collectors_request_deleter>;

/// mkorchestra_collectors_response_deleter is a deleter for
/// mkorchestra_collectors_response_t.
struct mkorchestra_collectors_response_deleter {
  void operator()(mkorchestra_collectors_response_t *s) {
    mkorchestra_collectors_response_delete(s);
  }
};

/// mkorchestra_collectors_response_uptr is a unique pointer to a
/// mkorchestra_collectors_response_t instance.
using mkorchestra_collectors_response_uptr = std::unique_ptr<
    mkorchestra_collectors_response_t, mkorchestra_collectors_response_deleter>;

/// mkorchestra_ths_request_deleter is a deleter for
/// mkorchestra_ths_request_t.
struct mkorchestra_ths_request_deleter {
  void operator()(mkorchestra_ths_request_t *s) {
    mkorchestra_ths_request_delete(s);
  }
};

/// mkorchestra_ths_request_uptr is a unique pointer to a
/// mkorchestra_ths_request_t instance.
using mkorchestra_ths_request_uptr = std::unique_ptr<
    mkorchestra_ths_request_t, mkorchestra_ths_request_deleter>;

/// mkorchestra_ths_response_deleter is a deleter for
/// mkorchestra_ths_response_t.
struct mkorchestra_ths_response_deleter {
  void operator()(mkorchestra_ths_response_t *s) {
    mkorchestra_ths_response_delete(s);
  }
};

/// mkorchestra_ths_response_uptr is a unique pointer to a
/// mkorchestra_ths_response_t instance.
using mkorchestra_ths_response_uptr = std::unique_ptr<
    mkorchestra_ths_response_t, mkorchestra_ths_response_deleter>;

/// mkorchestra_register_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_register_response_moveout_logs(
    mkorchestra_register_response_uptr &response);

/// mkorchestra_login_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_login_response_moveout_logs(
    mkorchestra_login_response_uptr &response);

/// mkorchestra_update_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_update_response_moveout_logs(
    mkorchestra_update_response_uptr &response);

/// mkorchestra_collectors_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_collectors_response_moveout_logs(
    mkorchestra_collectors_response_uptr &response);

/// mkorchestra_ths_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_ths_response_moveout_logs(
    mkorchestra_ths_response_uptr &response);

// The implementation can be included inline by defining this preprocessor
// symbol. If you only care about API, you can stop reading here.
#ifdef MKORCHESTRA_INLINE_IMPL

#include <vector>

#include "json.hpp"
#include "mkcurl.h"

#define MKORCHESTRA_CLIENT_METADATA(XX) \
  XX(std::string, available_bandwidth)  \
  XX(std::string, device_token)         \
  XX(std::string, language)             \
  XX(std::string, network_type)         \
  XX(std::string, platform)             \
  XX(std::string, probe_asn)            \
  XX(std::string, probe_cc)             \
  XX(std::string, probe_family)         \
  XX(std::string, probe_timezone)       \
  XX(std::string, software_name)        \
  XX(std::string, software_version)     \
  XX(std::vector<std::string>, supported_tests)

struct mkorchestra_metadata {
#define declare_attribute(type_, value_) type_ value_;
  MKORCHESTRA_CLIENT_METADATA(declare_attribute)
#undef declare_attribute
};

mkorchestra_metadata_t *mkorchestra_metadata_new_nonnull() {
  return new mkorchestra_metadata_t;
}

void mkorchestra_metadata_set_available_bandwidth(
    mkorchestra_metadata_t *metadata,
    const char *available_bandwidth) {
  if (metadata == nullptr || available_bandwidth == nullptr) {
    abort();
  }
  metadata->available_bandwidth = available_bandwidth;
}

void mkorchestra_metadata_set_device_token(
    mkorchestra_metadata_t *metadata,
    const char *device_token) {
  if (metadata == nullptr || device_token == nullptr) {
    abort();
  }
  metadata->device_token = device_token;
}

void mkorchestra_metadata_set_language(
    mkorchestra_metadata_t *metadata,
    const char *language) {
  if (metadata == nullptr || language == nullptr) {
    abort();
  }
  metadata->language = language;
}

void mkorchestra_metadata_set_network_type(
    mkorchestra_metadata_t *metadata,
    const char *network_type) {
  if (metadata == nullptr || network_type == nullptr) {
    abort();
  }
  metadata->network_type = network_type;
}

void mkorchestra_metadata_set_platform(
    mkorchestra_metadata_t *metadata,
    const char *platform) {
  if (metadata == nullptr || platform == nullptr) {
    abort();
  }
  metadata->platform = platform;
}

void mkorchestra_metadata_set_probe_asn(
    mkorchestra_metadata_t *metadata,
    const char *probe_asn) {
  if (metadata == nullptr || probe_asn == nullptr) {
    abort();
  }
  metadata->probe_asn = probe_asn;
}

void mkorchestra_metadata_set_probe_cc(
    mkorchestra_metadata_t *metadata,
    const char *probe_cc) {
  if (metadata == nullptr || probe_cc == nullptr) {
    abort();
  }
  metadata->probe_cc = probe_cc;
}

void mkorchestra_metadata_set_probe_family(
    mkorchestra_metadata_t *metadata,
    const char *probe_family) {
  if (metadata == nullptr || probe_family == nullptr) {
    abort();
  }
  metadata->probe_family = probe_family;
}

void mkorchestra_metadata_set_probe_timezone(
    mkorchestra_metadata_t *metadata,
    const char *probe_timezone) {
  if (metadata == nullptr || probe_timezone == nullptr) {
    abort();
  }
  metadata->probe_timezone = probe_timezone;
}

void mkorchestra_metadata_set_software_name(
    mkorchestra_metadata_t *metadata,
    const char *software_name) {
  if (metadata == nullptr || software_name == nullptr) {
    abort();
  }
  metadata->software_name = software_name;
}

void mkorchestra_metadata_set_software_version(
    mkorchestra_metadata_t *metadata,
    const char *software_version) {
  if (metadata == nullptr || software_version == nullptr) {
    abort();
  }
  metadata->software_version = software_version;
}

void mkorchestra_metadata_add_supported_test(
    mkorchestra_metadata_t *metadata,
    const char *supported_test) {
  if (metadata == nullptr || supported_test == nullptr) {
    abort();
  }
  metadata->supported_tests.push_back(supported_test);
}

void mkorchestra_metadata_delete(
    mkorchestra_metadata_t *metadata) {
  delete metadata;
}

struct mkorchestra_register_request {
  std::string password;
  mkorchestra_metadata_t metadata;  // We make a copy, so no pointer
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_register_response {
  int64_t good = false;
  std::string client_id;
  std::string logs;
};

mkorchestra_register_request_t *mkorchestra_register_request_new_nonnull() {
  return new mkorchestra_register_request_t;
}

void mkorchestra_register_request_set_password(
    mkorchestra_register_request_t *request,
    const char *password) {
  if (request == nullptr || password == nullptr) {
    abort();
  }
  request->password = password;
}

void mkorchestra_register_request_set_metadata(
    mkorchestra_register_request_t *request,
    const mkorchestra_metadata_t *metadata) {
  if (request == nullptr || metadata == nullptr) {
    abort();
  }
  request->metadata = *metadata;  // Make a copy
}

void mkorchestra_register_request_set_base_url(
    mkorchestra_register_request_t *request, const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_register_request_set_ca_bundle_path(
    mkorchestra_register_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_register_request_set_timeout(
    mkorchestra_register_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

mkorchestra_register_response_t *mkorchestra_register_request_perform_nonnull(
    const mkorchestra_register_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_register_response_uptr response{
      new mkorchestra_register_response_t};  // new cannot fail
  mkcurl_request_uptr curl_request{mkcurl_request_new_nonnull()};
  mkcurl_request_set_ca_bundle_path_v2(
      curl_request.get(), request->ca_bundle_path.c_str());
  mkcurl_request_set_timeout_v2(curl_request.get(), request->timeout);
  mkcurl_request_set_method_post_v2(curl_request.get());
  mkcurl_request_add_header_v2(
      curl_request.get(), "Content-Type: application/json");
  {
    std::string url = request->base_url;
    url += "/api/v1/register";
    mkcurl_request_set_url_v2(curl_request.get(), url.c_str());
  }
  {
    std::string body;
    nlohmann::json doc;
    doc["password"] = request->password;
#define maybe_add(type_, name_)               \
  do {                                        \
    if (!request->metadata.name_.empty()) {   \
      doc[#name_] = request->metadata.name_;  \
    }                                         \
  } while (0);
    MKORCHESTRA_CLIENT_METADATA(maybe_add)
#undef maybe_add
    try {
      body = doc.dump();
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
    response->logs += "Request body: ";
    response->logs += body;
    response->logs += "\n";
    mkcurl_request_movein_body_v2(curl_request, std::move(body));
  }
  mkcurl_response_uptr curl_response{
      mkcurl_request_perform_nonnull(curl_request.get())};
  response->logs += mkcurl_response_moveout_logs_v2(curl_response);
  if (mkcurl_response_get_error_v2(curl_response.get()) != 0) {
    return response.release();
  }
  if (mkcurl_response_get_status_code_v2(curl_response.get()) != 200) {
    return response.release();
  }
  {
    std::string body = mkcurl_response_moveout_body_v2(curl_response);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    nlohmann::json doc;
    try {
      doc = nlohmann::json::parse(body);
      response->client_id = doc.at("client_id").get<std::string>();
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
  }
  response->good = true;
  return response.release();
}

void mkorchestra_register_request_delete(
    mkorchestra_register_request_t *request) {
  delete request;
}

int64_t mkorchestra_register_response_good(
    const mkorchestra_register_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

const char *mkorchestra_register_response_get_client_id(
    const mkorchestra_register_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->client_id.c_str();
}

void mkorchestra_register_response_get_binary_logs(
    const mkorchestra_register_response_t *response,
    const uint8_t **data, size_t *count) {
  if (response == nullptr || data == nullptr || count == nullptr) {
    abort();
  }
  *data = (const uint8_t *)response->logs.c_str();
  *count = response->logs.size();
}

void mkorchestra_register_response_delete(
    mkorchestra_register_response_t *response) {
  delete response;
}

struct mkorchestra_login_request {
  std::string username;
  std::string password;
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_login_response {
  int64_t good = false;
  std::string expire;
  std::string token;
  std::string logs;
};

mkorchestra_login_request_t *mkorchestra_login_request_new_nonnull() {
  return new mkorchestra_login_request_t;
}

void mkorchestra_login_request_set_username(
    mkorchestra_login_request_t *request,
    const char *username) {
  if (request == nullptr || username == nullptr) {
    abort();
  }
  request->username = username;
}

void mkorchestra_login_request_set_password(
    mkorchestra_login_request_t *request,
    const char *password) {
  if (request == nullptr || password == nullptr) {
    abort();
  }
  request->password = password;
}

void mkorchestra_login_request_set_base_url(
    mkorchestra_login_request_t *request, const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_login_request_set_ca_bundle_path(
    mkorchestra_login_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_login_request_set_timeout(
    mkorchestra_login_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

mkorchestra_login_response_t *mkorchestra_login_request_perform_nonnull(
    const mkorchestra_login_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_login_response_uptr response{
    new mkorchestra_login_response_t};  // new cannot fail
  mkcurl_request_uptr curl_request{mkcurl_request_new_nonnull()};
  mkcurl_request_set_ca_bundle_path_v2(
      curl_request.get(), request->ca_bundle_path.c_str());
  mkcurl_request_set_timeout_v2(curl_request.get(), request->timeout);
  mkcurl_request_set_method_post_v2(curl_request.get());
  mkcurl_request_add_header_v2(
      curl_request.get(), "Content-Type: application/json");
  {
    std::string url = request->base_url;
    url += "/api/v1/login";
    mkcurl_request_set_url_v2(curl_request.get(), url.c_str());
  }
  {
    std::string body;
    nlohmann::json doc;
    doc["username"] = request->username;
    doc["password"] = request->password;
    try {
      body = doc.dump();
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
    response->logs += "Request body: ";
    response->logs += body;
    response->logs += "\n";
    mkcurl_request_movein_body_v2(curl_request, std::move(body));
  }
  mkcurl_response_uptr curl_response{
      mkcurl_request_perform_nonnull(curl_request.get())};
  response->logs += mkcurl_response_moveout_logs_v2(curl_response);
  if (mkcurl_response_get_error_v2(curl_response.get()) != 0) {
    return response.release();
  }
  if (mkcurl_response_get_status_code_v2(curl_response.get()) != 200) {
    return response.release();
  }
  {
    std::string body = mkcurl_response_moveout_body_v2(curl_response);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    nlohmann::json doc;
    try {
      doc = nlohmann::json::parse(body);
      response->expire = doc.at("expire").get<std::string>();
      response->token = doc.at("token").get<std::string>();
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
  }
  response->good = true;
  return response.release();
}

void mkorchestra_login_request_delete(mkorchestra_login_request_t *request) {
  delete request;
}

int64_t mkorchestra_login_response_good(
    const mkorchestra_login_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

const char *mkorchestra_login_response_get_expire(
    const mkorchestra_login_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->expire.c_str();
}

const char *mkorchestra_login_response_get_token(
    const mkorchestra_login_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->token.c_str();
}

void mkorchestra_login_response_delete(
    mkorchestra_login_response_t *response) {
  delete response;
}

struct mkorchestra_update_request {
  std::string token;
  std::string client_id;
  mkorchestra_metadata_t metadata;  // We make a copy, so no pointer
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_update_response {
  int64_t good = false;
  std::string logs;
};

mkorchestra_update_request_t *mkorchestra_update_request_new_nonnull() {
  return new mkorchestra_update_request_t;
}

void mkorchestra_update_request_set_token(
    mkorchestra_update_request_t *request,
    const char *token) {
  if (request == nullptr || token == nullptr) {
    abort();
  }
  request->token = token;
}

void mkorchestra_update_request_set_client_id(
    mkorchestra_update_request_t *request,
    const char *client_id) {
  if (request == nullptr || client_id == nullptr) {
    abort();
  }
  request->client_id = client_id;
}

void mkorchestra_update_request_set_metadata(
    mkorchestra_update_request_t *request,
    const mkorchestra_metadata_t *metadata) {
  if (request == nullptr || metadata == nullptr) {
    abort();
  }
  request->metadata = *metadata;  // Make a copy
}

void mkorchestra_update_request_set_base_url(
    mkorchestra_update_request_t *request, const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_update_request_set_ca_bundle_path(
    mkorchestra_update_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_update_request_set_timeout(
    mkorchestra_update_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

mkorchestra_update_response_t *mkorchestra_update_request_perform_nonnull(
    const mkorchestra_update_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_update_response_uptr response{
      new mkorchestra_update_response_t};  // new cannot fail
  mkcurl_request_uptr curl_request{mkcurl_request_new_nonnull()};
  mkcurl_request_set_ca_bundle_path_v2(
      curl_request.get(), request->ca_bundle_path.c_str());
  mkcurl_request_set_timeout_v2(curl_request.get(), request->timeout);
  mkcurl_request_set_method_put_v2(curl_request.get());
  mkcurl_request_add_header_v2(
      curl_request.get(), "Content-Type: application/json");
  {
    std::string header = "Authorization: Bearer ";
    header += request->token;
    mkcurl_request_add_header_v2(curl_request.get(), header.c_str());
  }
  {
    std::string url = request->base_url;
    url += "/api/v1/update/";
    url += request->client_id;
    mkcurl_request_set_url_v2(curl_request.get(), url.c_str());
  }
  {
    std::string body;
    nlohmann::json doc;
#define maybe_add(type_, name_)               \
  do {                                        \
    if (!request->metadata.name_.empty()) {   \
      doc[#name_] = request->metadata.name_;  \
    }                                         \
  } while (0);
    MKORCHESTRA_CLIENT_METADATA(maybe_add)
#undef maybe_add
    try {
      body = doc.dump();
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
    response->logs += "Request body: ";
    response->logs += body;
    response->logs += "\n";
    mkcurl_request_movein_body_v2(curl_request, std::move(body));
  }
  mkcurl_response_uptr curl_response{
      mkcurl_request_perform_nonnull(curl_request.get())};
  response->logs += mkcurl_response_moveout_logs_v2(curl_response);
  if (mkcurl_response_get_error_v2(curl_response.get()) != 0) {
    return response.release();
  }
  if (mkcurl_response_get_status_code_v2(curl_response.get()) != 200) {
    return response.release();
  }
  {
    std::string body = mkcurl_response_moveout_body_v2(curl_response);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
  }
  response->good = true;
  return response.release();
}

void mkorchestra_update_request_delete(
    mkorchestra_update_request_t *request) {
  delete request;
}

int64_t mkorchestra_update_response_good(
    const mkorchestra_update_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

void mkorchestra_update_response_get_binary_logs(
    const mkorchestra_update_response_t *response,
    const uint8_t **data, size_t *count) {
  if (response == nullptr || data == nullptr || count == nullptr) {
    abort();
  }
  *data = (const uint8_t *)response->logs.c_str();
  *count = response->logs.size();
}

void mkorchestra_update_response_delete(
    mkorchestra_update_response_t *response) {
  delete response;
}

struct mkorchestra_collectors_request {
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_collectors_response {
  int64_t good = false;
  std::vector<std::string> https_collectors;
  std::string logs;
};

mkorchestra_collectors_request_t *
mkorchestra_collectors_request_new_nonnull() {
  return new mkorchestra_collectors_request_t;
}

void mkorchestra_collectors_request_set_base_url(
    mkorchestra_collectors_request_t *request,
    const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_collectors_request_set_ca_bundle_path(
    mkorchestra_collectors_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_collectors_request_set_timeout(
    mkorchestra_collectors_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

mkorchestra_collectors_response_t *
mkorchestra_collectors_request_perform_nonnull(
    const mkorchestra_collectors_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_collectors_response_uptr response{
      new mkorchestra_collectors_response_t};  // new cannot fail
  mkcurl_request_uptr curl_request{mkcurl_request_new_nonnull()};
  mkcurl_request_set_ca_bundle_path_v2(
      curl_request.get(), request->ca_bundle_path.c_str());
  mkcurl_request_set_timeout_v2(curl_request.get(), request->timeout);
  {
    std::string url = request->base_url;
    url += "/api/v1/collectors";
    mkcurl_request_set_url_v2(curl_request.get(), url.c_str());
  }
  mkcurl_response_uptr curl_response{
      mkcurl_request_perform_nonnull(curl_request.get())};
  response->logs += mkcurl_response_moveout_logs_v2(curl_response);
  if (mkcurl_response_get_error_v2(curl_response.get()) != 0) {
    return response.release();
  }
  if (mkcurl_response_get_status_code_v2(curl_response.get()) != 200) {
    return response.release();
  }
  {
    std::string body = mkcurl_response_moveout_body_v2(curl_response);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    try {
      nlohmann::json doc = nlohmann::json::parse(body);
      for (auto entry : doc.at("results")) {
        if (entry.at("type") == "https") {
          response->https_collectors.push_back(entry.at("address"));
        }
      }
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
  }
  response->good = true;
  return response.release();
}

void mkorchestra_collectors_request_delete(
    mkorchestra_collectors_request_t *request) {
  delete request;
}

int64_t mkorchestra_collectors_response_good(
    const mkorchestra_collectors_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

size_t mkorchestra_collectors_response_get_https_collectors_size(
    const mkorchestra_collectors_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->https_collectors.size();
}

const char *mkorchestra_collectors_response_get_https_collector_at(
    const mkorchestra_collectors_response_t *response, size_t idx) {
  if (response == nullptr) {
    abort();
  }
  if (idx >= response->https_collectors.size()) return "";
  return response->https_collectors[idx].c_str();
}

void mkorchestra_collectors_response_get_binary_logs(
    const mkorchestra_collectors_response_t *response,
    const uint8_t **data, size_t *count) {
  if (response == nullptr || data == nullptr || count == nullptr) {
    abort();
  }
  *data = (const uint8_t *)response->logs.c_str();
  *count = response->logs.size();
}

void mkorchestra_collectors_response_delete(
    mkorchestra_collectors_response_t *response) {
  delete response;
}

struct mkorchestra_ths_request {
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_ths_response {
  int64_t good = false;
  std::vector<std::string> wchttpsths;  // Web Connectivity https ths
  std::string logs;
};

mkorchestra_ths_request_t *
mkorchestra_ths_request_new_nonnull() {
  return new mkorchestra_ths_request_t;
}

void mkorchestra_ths_request_set_base_url(
    mkorchestra_ths_request_t *request,
    const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_ths_request_set_ca_bundle_path(
    mkorchestra_ths_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_ths_request_set_timeout(
    mkorchestra_ths_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

mkorchestra_ths_response_t *
mkorchestra_ths_request_perform_nonnull(
    const mkorchestra_ths_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_ths_response_uptr response{
      new mkorchestra_ths_response_t};  // new cannot fail
  mkcurl_request_uptr curl_request{mkcurl_request_new_nonnull()};
  mkcurl_request_set_ca_bundle_path_v2(
      curl_request.get(), request->ca_bundle_path.c_str());
  mkcurl_request_set_timeout_v2(curl_request.get(), request->timeout);
  {
    std::string url = request->base_url;
    url += "/api/v1/test-helpers";
    mkcurl_request_set_url_v2(curl_request.get(), url.c_str());
  }
  mkcurl_response_uptr curl_response{
      mkcurl_request_perform_nonnull(curl_request.get())};
  response->logs += mkcurl_response_moveout_logs_v2(curl_response);
  if (mkcurl_response_get_error_v2(curl_response.get()) != 0) {
    return response.release();
  }
  if (mkcurl_response_get_status_code_v2(curl_response.get()) != 200) {
    return response.release();
  }
  {
    std::string body = mkcurl_response_moveout_body_v2(curl_response);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    try {
      nlohmann::json doc = nlohmann::json::parse(body);
      for (auto entry : doc.at("results")) {
        if (entry.at("name") == "web-connectivity") {
          if (entry.at("type") == "https") {
            response->wchttpsths.push_back(entry.at("address"));
          } else if (entry.at("address") == "https") {
            response->logs += "Working around ooni/orchestra#54 issue.\n";
            response->wchttpsths.push_back(entry.at("type"));
          }
        }
      }
    } catch (const std::exception &exc) {
      response->logs += exc.what();
      response->logs += "\n";
      return response.release();
    }
  }
  response->good = true;
  return response.release();
}

void mkorchestra_ths_request_delete(
    mkorchestra_ths_request_t *request) {
  delete request;
}

int64_t mkorchestra_ths_response_good(
    const mkorchestra_ths_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

size_t mkorchestra_ths_response_get_wchttpsths_size(
    const mkorchestra_ths_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->wchttpsths.size();
}

const char *mkorchestra_ths_response_get_wchttpsth_at(
    const mkorchestra_ths_response_t *response, size_t idx) {
  if (response == nullptr) {
    abort();
  }
  if (idx >= response->wchttpsths.size()) return "";
  return response->wchttpsths[idx].c_str();
}

void mkorchestra_ths_response_get_binary_logs(
    const mkorchestra_ths_response_t *response,
    const uint8_t **data, size_t *count) {
  if (response == nullptr || data == nullptr || count == nullptr) {
    abort();
  }
  *data = (const uint8_t *)response->logs.c_str();
  *count = response->logs.size();
}

void mkorchestra_ths_response_delete(
    mkorchestra_ths_response_t *response) {
  delete response;
}

std::string mkorchestra_register_response_moveout_logs(
    mkorchestra_register_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

std::string mkorchestra_login_response_moveout_logs(
    mkorchestra_login_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

std::string mkorchestra_update_response_moveout_logs(
    mkorchestra_update_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

std::string mkorchestra_collectors_response_moveout_logs(
    mkorchestra_collectors_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

std::string mkorchestra_ths_response_moveout_logs(
    mkorchestra_ths_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

#endif  // MKORCHESTRA_INLINE_IMPL
#endif  // __cplusplus
#endif  // MEASUREMENT_KIT_MKORCHESTRA_H
