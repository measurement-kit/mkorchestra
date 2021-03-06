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

/// mkorchestra_collector_t is a collector.
typedef struct mkorchestra_collector mkorchestra_collector_t;

/// mkorchestra_collector_get_type returns the collector type. It always
/// returns a valid string. Aborts if passed a null pointer.
const char *mkorchestra_collector_get_type(const mkorchestra_collector_t *c);

/// mkorchestra_collector_get_address returns the collector address. It always
/// returns a valid string. Aborts if passed a null pointer.
const char *mkorchestra_collector_get_address(const mkorchestra_collector_t *c);

/// mkorchestra_collector_delete delets @p c, which MAY be null.
void mkorchestra_collector_delete(mkorchestra_collector_t *c);

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

/// mkorchestra_collectors_response_get_collectors_size returns the
/// number of available collectors. This function aborts if passed
/// a null pointer @p response.
size_t mkorchestra_collectors_response_get_collectors_size(
    const mkorchestra_collectors_response_t *response);

/// mkorchestra_collectors_response_get_collector_at returns the
/// collector at index @p idx. It never returns an invalid or null
/// pointer. This function aborts if passed a null @p response or
/// if the provided @p idx is out of range.
mkorchestra_collector_t *mkorchestra_collectors_response_get_collector_at(
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

/// mkorchestra_testhelper_t is a test helper.
typedef struct mkorchestra_testhelper mkorchestra_testhelper_t;

/// mkorchestra_testhelper_get_name returns the name of a test helper. The
/// returned string is owned by @p th. This function aborts if @p th is null.
const char *mkorchestra_testhelper_get_name(
    const mkorchestra_testhelper_t *th);

/// mkorchestra_testhelper_get_type returns the type of a test helper. The
/// returned string is owned by @p th. This function aborts if @p th is null.
const char *mkorchestra_testhelper_get_type(
    const mkorchestra_testhelper_t *th);

/// mkorchestra_testhelper_get_address returns the address of a test helper. The
/// returned string is owned by @p th. This function aborts if @p th is null.
const char *mkorchestra_testhelper_get_address(
    const mkorchestra_testhelper_t *th);

/// mkorchestra_testhelper_delete deletes @p th, which MAY be null.
void mkorchestra_testhelper_delete(mkorchestra_testhelper_t *th);

/// mkorchestra_testhelpers_request_t is a request for the test-helpers API.
typedef struct mkorchestra_testhelpers_request mkorchestra_testhelpers_request_t;

/// mkorchestra_testhelpers_response_t is a response for the test-helpers API.
typedef struct mkorchestra_testhelpers_response mkorchestra_testhelpers_response_t;

/// mkorchestra_testhelpers_request_new_nonnull creates a new request for the
/// test-helpers endpoint. The returned pointer is always valid. This function
/// calls abort if allocating new memory fails.
mkorchestra_testhelpers_request_t *
mkorchestra_testhelpers_request_new_nonnull(void);

/// mkorchestra_testhelpers_request_set_base_url sets the base URL for
/// the @p request. It aborts if passed any null pointer.
void mkorchestra_testhelpers_request_set_base_url(
    mkorchestra_testhelpers_request_t *request,
    const char *base_url);

/// mkorchestra_testhelpers_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_testhelpers_request_set_ca_bundle_path(
    mkorchestra_testhelpers_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_testhelpers_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_testhelpers_request_set_timeout(
    mkorchestra_testhelpers_request_t *request,
    int64_t timeout);

/// mkorchestra_testhelpers_request_perform_nonnull performs @p request. It
/// always returns a valid pointer. It aborts if allocation fails.
mkorchestra_testhelpers_response_t *
mkorchestra_testhelpers_request_perform_nonnull(
    const mkorchestra_testhelpers_request_t *request);

/// mkorchestra_testhelpers_request_delete destroys @p request. Note that
/// @p request MAY be a null pointer.
void mkorchestra_testhelpers_request_delete(
    mkorchestra_testhelpers_request_t *request);

/// mkorchestra_testhelpers_response_good returns true if we received a response
/// from the API and such response indicated success, false otherwise. It
/// calls abort if @p response is a null pointer.
int64_t mkorchestra_testhelpers_response_good(
    const mkorchestra_testhelpers_response_t *response);

/// mkorchestra_testhelpers_response_get_testhelpers_size returns the number
/// of available test helpers. This function aborts if passed a null pointer @p
/// response.
size_t mkorchestra_testhelpers_response_get_testhelpers_size(
    const mkorchestra_testhelpers_response_t *response);

/// mkorchestra_testhelpers_response_get_testhelper_at returns the test helper
/// at index @p idx. This function aborts if passed a null @p response or if
/// @p idx is out of range. The returned pointer is always valid.
mkorchestra_testhelper_t *mkorchestra_testhelpers_response_get_testhelper_at(
    const mkorchestra_testhelpers_response_t *response, size_t idx);

/// mkorchestra_testhelpers_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_testhelpers_response_get_binary_logs(
    const mkorchestra_testhelpers_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_testhelpers_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_testhelpers_response_delete(
    mkorchestra_testhelpers_response_t *response);

/// mkorchestra_urls_request_t is a request to the urls API.
typedef struct mkorchestra_urls_request mkorchestra_urls_request_t;

/// mkorchestra_urls_response_t is a response from the urls API.
typedef struct mkorchestra_urls_response mkorchestra_urls_response_t;

/// mkorchestra_urls_request_new_nonnull creates a new urls request. It will
/// always return a valid pointer and will abort if out of memory.
mkorchestra_urls_request_t *mkorchestra_urls_request_new_nonnull(void);

/// mkorchestra_urls_request_set_limit sets the maximum number of URLs to
/// return in a page. It will abort if passed any null pointer argument.
void mkorchestra_urls_request_set_limit(
    mkorchestra_urls_request_t *request,
    int64_t limit);

/// mkorchestra_urls_request_set_country_code sets the country code. It
/// will abort if passed any null pointer argument.
void mkorchestra_urls_request_set_country_code(
    mkorchestra_urls_request_t *request,
    const char *country_code);

/// mkorchestra_urls_request_add_category_code adds a URL category. It
/// will abort if passed any null pointer argument.
void mkorchestra_urls_request_add_category_code(
    mkorchestra_urls_request_t *request,
    const char *category_code);

/// mkorchestra_urls_request_set_base_url sets the base URL for
/// the @p request. It will abort if passed null pointers.
void mkorchestra_urls_request_set_base_url(
    mkorchestra_urls_request_t *request,
    const char *base_url);

/// mkorchestra_urls_request_set_ca_bundle_path sets the CA bundle
/// path. Required on mobile. Aborts if passed null arguments.
void mkorchestra_urls_request_set_ca_bundle_path(
    mkorchestra_urls_request_t *request,
    const char *ca_bundle_path);

/// mkorchestra_urls_request_set_timeout sets the timeout. After that time has
/// expired, the request will fail. It aborts if passed null arguments.
void mkorchestra_urls_request_set_timeout(
    mkorchestra_urls_request_t *request,
    int64_t timeout);

/// mkorchestra_urls_request_perform_nonnull performs @p request. It will
/// always return a valid pointer. It aborts if passed a null @p request.
mkorchestra_urls_response_t *mkorchestra_urls_request_perform_nonnull(
    const mkorchestra_urls_request_t *request);

/// mkorchestra_urls_request_delete destroys @p request. Note that @p
/// request MAY be a null pointer.
void mkorchestra_urls_request_delete(mkorchestra_urls_request_t *request);

/// mkorchestra_urls_response_good returns true if we received a response
/// from the API and that response is successful, false otherwise. It
/// calls abort if passed a null pointer argument.
int64_t mkorchestra_urls_response_good(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_metadata_count returns the count field of
/// the metadata. This function will call abort if passed a null pointer.
int64_t mkorchestra_urls_response_get_metadata_count(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_metadata_current_page returns the current
/// page field of the metadata. It will abort if passed a null pointer.
int64_t mkorchestra_urls_response_get_metadata_current_page(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_metadata_limit returns the limit field of
/// the metadata. It will abort if passed a null pointer.
int64_t mkorchestra_urls_response_get_metadata_limit(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_metadata_next_url returns the next URL field
/// of the metadata. It always returns a valid string owned by @p response,
/// which MAY be an empty string. It aborts if passed a null pointer.
const char *mkorchestra_urls_response_get_metadata_next_url(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_metadata_pages returns the pages field of
/// the metadata. It will abort if passed a null pointer.
int64_t mkorchestra_urls_response_get_metadata_pages(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_results_size returns the number of entries
/// that have been returned as results. It will abort if passed a null pointer.
size_t mkorchestra_urls_response_get_results_size(
    const mkorchestra_urls_response_t *response);

/// mkorchestra_urls_response_get_result_category_code_at returns the category
/// code of the results entry at @p idx. It always returns a valid string owned
/// by @p response, which MAY be an empty string. It aborts if passed a null
/// pointer and if the provided @p idx is out of bounds.
const char *mkorchestra_urls_response_get_result_category_code_at(
    const mkorchestra_urls_response_t *response, size_t idx);

/// mkorchestra_urls_response_get_result_country_code_at returns the country
/// code of the results entry at @p idx. It always returns a valid string owned
/// by @p response, which MAY be an empty string. It aborts if passed a null
/// pointer and if the provided @p idx is out of bounds.
const char *mkorchestra_urls_response_get_result_country_code_at(
    const mkorchestra_urls_response_t *response, size_t idx);

/// mkorchestra_urls_response_get_result_url_at returns the URLof the results
/// entry at @p idx. It always returns a valid string owned by @p response,
/// which MAY be an empty string. It aborts if passed a null pointer and if the
/// provided @p idx is out of bounds.
const char *mkorchestra_urls_response_get_result_url_at(
    const mkorchestra_urls_response_t *response, size_t idx);

/// mkorchestra_urls_response_get_binary_logs returns the (possibly
/// non UTF-8) logs in @p data and @p count. The byte array returned in @p
/// data is owned by @p response and becomes invalid after @p response
/// is deleted. It aborts if passed any null pointer argument.
void mkorchestra_urls_response_get_binary_logs(
    const mkorchestra_urls_response_t *response,
    const uint8_t **data, size_t *count);

/// mkorchestra_urls_response_delete destroys @p response. Note that
/// @p response MAY be a null pointer.
void mkorchestra_urls_response_delete(
    mkorchestra_urls_response_t *response);

#ifdef __cplusplus
}  // extern "C"

#include <deque>
#include <memory>
#include <regex>
#include <sstream>
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

/// mkorchestra_collector_deleter is a deleter for
/// mkorchestra_collector_t.
struct mkorchestra_collector_deleter {
  void operator()(mkorchestra_collector_t *s) {
    mkorchestra_collector_delete(s);
  }
};

/// mkorchestra_collector_uptr is a unique pointer to a
/// mkorchestra_collector_t instance.
using mkorchestra_collector_uptr = std::unique_ptr<
    mkorchestra_collector_t, mkorchestra_collector_deleter>;

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

/// mkorchestra_testhelper_deleter is a deleter for
/// mkorchestra_testhelper_t.
struct mkorchestra_testhelper_deleter {
  void operator()(mkorchestra_testhelper_t *s) {
    mkorchestra_testhelper_delete(s);
  }
};

/// mkorchestra_testhelper_uptr is a unique pointer to a
/// mkorchestra_testhelper_t instance.
using mkorchestra_testhelper_uptr = std::unique_ptr<
    mkorchestra_testhelper_t, mkorchestra_testhelper_deleter>;

/// mkorchestra_testhelpers_request_deleter is a deleter for
/// mkorchestra_testhelpers_request_t.
struct mkorchestra_testhelpers_request_deleter {
  void operator()(mkorchestra_testhelpers_request_t *s) {
    mkorchestra_testhelpers_request_delete(s);
  }
};

/// mkorchestra_testhelpers_request_uptr is a unique pointer to a
/// mkorchestra_testhelpers_request_t instance.
using mkorchestra_testhelpers_request_uptr = std::unique_ptr<
    mkorchestra_testhelpers_request_t, mkorchestra_testhelpers_request_deleter>;

/// mkorchestra_testhelpers_response_deleter is a deleter for
/// mkorchestra_testhelpers_response_t.
struct mkorchestra_testhelpers_response_deleter {
  void operator()(mkorchestra_testhelpers_response_t *s) {
    mkorchestra_testhelpers_response_delete(s);
  }
};

/// mkorchestra_testhelpers_response_uptr is a unique pointer to a
/// mkorchestra_testhelpers_response_t instance.
using mkorchestra_testhelpers_response_uptr = std::unique_ptr<
    mkorchestra_testhelpers_response_t, mkorchestra_testhelpers_response_deleter>;

/// mkorchestra_urls_request_deleter is a deleter for
/// mkorchestra_urls_request_t.
struct mkorchestra_urls_request_deleter {
  void operator()(mkorchestra_urls_request_t *s) {
    mkorchestra_urls_request_delete(s);
  }
};

/// mkorchestra_urls_request_uptr is a unique pointer to a
/// mkorchestra_urls_request_t instance.
using mkorchestra_urls_request_uptr = std::unique_ptr<
    mkorchestra_urls_request_t, mkorchestra_urls_request_deleter>;

/// mkorchestra_urls_response_deleter is a deleter for
/// mkorchestra_urls_response_t.
struct mkorchestra_urls_response_deleter {
  void operator()(mkorchestra_urls_response_t *s) {
    mkorchestra_urls_response_delete(s);
  }
};

/// mkorchestra_urls_response_uptr is a unique pointer to a
/// mkorchestra_urls_response_t instance.
using mkorchestra_urls_response_uptr = std::unique_ptr<
    mkorchestra_urls_response_t, mkorchestra_urls_response_deleter>;

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

/// mkorchestra_testhelpers_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_testhelpers_response_moveout_logs(
    mkorchestra_testhelpers_response_uptr &response);

/// mkorchestra_urls_response_moveout_logs moves the logs out of
/// @p response. It aborts if passed a null pointer.
std::string mkorchestra_urls_response_moveout_logs(
    mkorchestra_urls_response_uptr &response);

// The implementation can be included inline by defining this preprocessor
// symbol. If you only care about API, you can stop reading here.
#ifdef MKORCHESTRA_INLINE_IMPL

#include <vector>

#include "json.hpp"
#include "mkcurl.hpp"

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
  mk::curl::Request curl_request;
  curl_request.ca_path = request->ca_bundle_path;
  curl_request.timeout = request->timeout;
  curl_request.method = "POST";
  curl_request.headers.push_back("Content-Type: application/json");
  {
    std::string url = request->base_url;
    url += "/api/v1/register";
    curl_request.url = std::move(url);
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
    std::swap(curl_request.body, body);
  }
  mk::curl::Response curl_response = mk::curl::perform(curl_request);
  for (auto &log : curl_response.logs) {
    response->logs += log.line;
    response->logs += "\n";
  }
  if (curl_response.error != 0) {
    return response.release();
  }
  if (curl_response.status_code != 200) {
    return response.release();
  }
  {
    std::string body = std::move(curl_response.body);
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
  mk::curl::Request curl_request;
  curl_request.ca_path = request->ca_bundle_path;
  curl_request.timeout = request->timeout;
  curl_request.method = "POST";
  curl_request.headers.push_back("Content-Type: application/json");
  {
    std::string url = request->base_url;
    url += "/api/v1/login";
    std::swap(curl_request.url, url);
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
    std::swap(curl_request.body, body);
  }
  mk::curl::Response curl_response = mk::curl::perform(curl_request);
  for (auto &log : curl_response.logs) {
    response->logs += log.line;
    response->logs += "\n";
  }
  if (curl_response.error != 0) {
    return response.release();
  }
  if (curl_response.status_code != 200) {
    return response.release();
  }
  {
    std::string body = std::move(curl_response.body);
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
  mk::curl::Request curl_request;
  curl_request.ca_path = request->ca_bundle_path;
  curl_request.timeout = request->timeout;
  curl_request.method = "PUT";
  curl_request.headers.push_back("Content-Type: application/json");
  {
    std::string header = "Authorization: Bearer ";
    header += request->token;
    curl_request.headers.push_back(std::move(header));
  }
  {
    std::string url = request->base_url;
    url += "/api/v1/update/";
    url += request->client_id;
    std::swap(curl_request.url, url);
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
    std::swap(curl_request.body, body);
  }
  mk::curl::Response curl_response = mk::curl::perform(curl_request);
  for (auto &log : curl_response.logs) {
    response->logs += log.line;
    response->logs += "\n";
  }
  if (curl_response.error != 0) {
    return response.release();
  }
  if (curl_response.status_code != 200) {
    return response.release();
  }
  {
    std::string body = std::move(curl_response.body);
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

struct mkorchestra_collector {
  std::string type;
  std::string address;
};

const char *mkorchestra_collector_get_type(const mkorchestra_collector_t *c) {
  if (c == nullptr) {
    abort();
  }
  return c->type.c_str();
}

const char *mkorchestra_collector_get_address(
    const mkorchestra_collector_t *c) {
  if (c == nullptr) {
    abort();
  }
  return c->address.c_str();
}

void mkorchestra_collector_delete(mkorchestra_collector_t *c) { delete c; }

struct mkorchestra_collectors_request {
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_collectors_response {
  int64_t good = false;
  std::vector<mkorchestra_collector_uptr> collectors;
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
  mk::curl::Request curl_request;
  curl_request.ca_path = request->ca_bundle_path;
  curl_request.timeout = request->timeout;
  {
    std::string url = request->base_url;
    url += "/api/v1/collectors";
    std::swap(curl_request.url, url);
  }
  mk::curl::Response curl_response = mk::curl::perform(curl_request);
  for (auto &log : curl_response.logs) {
    response->logs += log.line;
    response->logs += "\n";
  }
  if (curl_response.error != 0) {
    return response.release();
  }
  if (curl_response.status_code != 200) {
    return response.release();
  }
  {
    std::string body = std::move(curl_response.body);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    try {
      nlohmann::json doc = nlohmann::json::parse(body);
      for (auto entry : doc.at("results")) {
        mkorchestra_collector_uptr c{new mkorchestra_collector_t};
        c->address = entry.at("address");
        c->type = entry.at("type");
        response->collectors.push_back(std::move(c));
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

size_t mkorchestra_collectors_response_get_collectors_size(
    const mkorchestra_collectors_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->collectors.size();
}

mkorchestra_collector_t *mkorchestra_collectors_response_get_collector_at(
    const mkorchestra_collectors_response_t *response, size_t idx) {
  if (response == nullptr || idx >= response->collectors.size()) {
    abort();
  }
  mkorchestra_collector_uptr c{new mkorchestra_collector_t};
  *c = *response->collectors[idx];
  return c.release();
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

struct mkorchestra_testhelper {
  std::string name;
  std::string type;
  std::string address;
};

const char *mkorchestra_testhelper_get_name(
    const mkorchestra_testhelper_t *th) {
  if (th == nullptr) {
    abort();
  }
  return th->name.c_str();
}

const char *mkorchestra_testhelper_get_type(
    const mkorchestra_testhelper_t *th) {
  if (th == nullptr) {
    abort();
  }
  return th->type.c_str();
}

const char *mkorchestra_testhelper_get_address(
    const mkorchestra_testhelper_t *th) {
  if (th == nullptr) {
    abort();
  }
  return th->address.c_str();
}

void mkorchestra_testhelper_delete(mkorchestra_testhelper_t *th) {
  delete th;
}

struct mkorchestra_testhelpers_request {
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30;
};

struct mkorchestra_testhelpers_response {
  int64_t good = false;
  std::vector<mkorchestra_testhelper_uptr> helpers;
  std::string logs;
};

mkorchestra_testhelpers_request_t *
mkorchestra_testhelpers_request_new_nonnull() {
  return new mkorchestra_testhelpers_request_t;
}

void mkorchestra_testhelpers_request_set_base_url(
    mkorchestra_testhelpers_request_t *request,
    const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_testhelpers_request_set_ca_bundle_path(
    mkorchestra_testhelpers_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_testhelpers_request_set_timeout(
    mkorchestra_testhelpers_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

mkorchestra_testhelpers_response_t *
mkorchestra_testhelpers_request_perform_nonnull(
    const mkorchestra_testhelpers_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_testhelpers_response_uptr response{
      new mkorchestra_testhelpers_response_t};  // new cannot fail
  mk::curl::Request curl_request;
  curl_request.ca_path = request->ca_bundle_path;
  curl_request.timeout = request->timeout;
  {
    std::string url = request->base_url;
    url += "/api/v1/test-helpers";
    std::swap(curl_request.url, url);
  }
  mk::curl::Response curl_response = mk::curl::perform(curl_request);
  for (auto &log : curl_response.logs) {
    response->logs += log.line;
    response->logs += "\n";
  }
  if (curl_response.error != 0) {
    return response.release();
  }
  if (curl_response.status_code != 200) {
    return response.release();
  }
  {
    std::string body = std::move(curl_response.body);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    try {
      nlohmann::json doc = nlohmann::json::parse(body);
      for (auto entry : doc.at("results")) {
        mkorchestra_testhelper_uptr th{new mkorchestra_testhelper_t};
        th->name = entry.at("name");
        th->address = entry.at("address");
        th->type = entry.at("type");
        response->helpers.push_back(std::move(th));
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

void mkorchestra_testhelpers_request_delete(
    mkorchestra_testhelpers_request_t *request) {
  delete request;
}

int64_t mkorchestra_testhelpers_response_good(
    const mkorchestra_testhelpers_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

size_t mkorchestra_testhelpers_response_get_testhelpers_size(
    const mkorchestra_testhelpers_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->helpers.size();
}

mkorchestra_testhelper_t *mkorchestra_testhelpers_response_get_testhelper_at(
    const mkorchestra_testhelpers_response_t *response, size_t idx) {
  if (response == nullptr || idx >= response->helpers.size()) {
    abort();
  }
  mkorchestra_testhelper_uptr th{new mkorchestra_testhelper_t};
  *th = *response->helpers[idx];
  return th.release();
}

void mkorchestra_testhelpers_response_get_binary_logs(
    const mkorchestra_testhelpers_response_t *response,
    const uint8_t **data, size_t *count) {
  if (response == nullptr || data == nullptr || count == nullptr) {
    abort();
  }
  *data = (const uint8_t *)response->logs.c_str();
  *count = response->logs.size();
}

void mkorchestra_testhelpers_response_delete(
    mkorchestra_testhelpers_response_t *response) {
  delete response;
}

struct mkorchestra_urls_request {
  int64_t limit = -1;
  std::string country_code;
  std::vector<std::string> category_codes;
  std::string base_url;
  std::string ca_bundle_path;
  int64_t timeout = 30 /* seconds */;
};

struct mkorchestra_urls_result_entry {
  std::string category_code;
  std::string country_code;
  std::string url;
};

struct mkorchestra_urls_response {
  int64_t good = false;
  struct {
    int64_t count = -1;
    int64_t current_page = -1;
    int64_t limit = -1;
    std::string next_url;
    int64_t pages = -1;
  } metadata;
  std::vector<mkorchestra_urls_result_entry> results;
  std::string logs;
};

mkorchestra_urls_request_t *mkorchestra_urls_request_new_nonnull() {
  return new mkorchestra_urls_request_t;
}

void mkorchestra_urls_request_set_limit(
    mkorchestra_urls_request_t *request,
    int64_t limit) {
  if (request == nullptr) {
    abort();
  }
  request->limit = limit;
}

void mkorchestra_urls_request_set_country_code(
    mkorchestra_urls_request_t *request,
    const char *country_code) {
  if (request == nullptr || country_code == nullptr) {
    abort();
  }
  request->country_code = country_code;
}

void mkorchestra_urls_request_add_category_code(
    mkorchestra_urls_request_t *request,
    const char *category_code) {
  if (request == nullptr || category_code == nullptr) {
    abort();
  }
  request->category_codes.push_back(category_code);
}

void mkorchestra_urls_request_set_base_url(
    mkorchestra_urls_request_t *request,
    const char *base_url) {
  if (request == nullptr || base_url == nullptr) {
    abort();
  }
  request->base_url = base_url;
}

void mkorchestra_urls_request_set_ca_bundle_path(
    mkorchestra_urls_request_t *request,
    const char *ca_bundle_path) {
  if (request == nullptr || ca_bundle_path == nullptr) {
    abort();
  }
  request->ca_bundle_path = ca_bundle_path;
}

void mkorchestra_urls_request_set_timeout(
    mkorchestra_urls_request_t *request,
    int64_t timeout) {
  if (request == nullptr) {
    abort();
  }
  request->timeout = timeout;
}

// urls_make_query_string makes a string from the parameters in @p request and
// returns whether the parameters are okay. Aborts if passed null args. Note
// that the @p query parameter will be cleared and will be an empty string if
// there are no parameters to be added to the query.
static bool urls_make_query_string(const mkorchestra_urls_request_t *request,
                                   std::string *query) {
  if (request == nullptr || query == nullptr) {
    abort();
  }
  *query = "";  // start over
  std::deque<std::string> couples;
  {
    // Step 1: build a map from string to string with the query.
    std::map<std::string, std::string> map;
    {
      // match checks whether @p s makes sense. Here the concern is not to
      // precisely validate the codes but to guarantee that there are no
      // unexpected characters requiring escaping of the query.
      auto match = [](const std::string &s) -> bool {
        std::smatch match;
        std::regex re{R"(^[A-Z]{1,10}$)"};
        return std::regex_match(s, match, re);
      };
      if (!request->country_code.empty()) {
        if (!match(request->country_code)) return false;
        map["country_code"] = request->country_code;
      }
      if (!request->category_codes.empty()) {
        // Convert to a deque to enable easier processing.
        std::deque<std::string> deque{request->category_codes.begin(),
                                      request->category_codes.end()};
        std::stringstream ss;
        while (!deque.empty()) {
          std::string s = std::move(deque.front());
          deque.pop_front();
          if (!match(s)) return false;
          ss << s;
          if (!deque.empty()) ss << ",";
        }
        map["category_codes"] = ss.str();
      }
      if (request->limit > 0) {
        map["limit"] = std::to_string(request->limit);
      }
    }
    // Step 2: join parameter name and parameter value into a vector
    for (auto iter : map) {
      std::stringstream ss;
      ss << std::move(iter.first) << "=" << std::move(iter.second);
      couples.push_back(ss.str());
    }
  }
  // Step 3: add the question mark and join couples into a string
  if (!couples.empty()) {
    *query += "?";
    while (!couples.empty()) {
      std::string s = std::move(couples.front());
      couples.pop_front();
      *query += s;
      if (!couples.empty()) *query += "&";
    }
  }
  return true;
}

mkorchestra_urls_response_t *mkorchestra_urls_request_perform_nonnull(
    const mkorchestra_urls_request_t *request) {
  if (request == nullptr) {
    abort();
  }
  mkorchestra_urls_response_uptr response{
      new mkorchestra_urls_response_t};  // new cannot fail
  mk::curl::Request curl_request;
  curl_request.ca_path = request->ca_bundle_path;
  curl_request.timeout = request->timeout;
  {
    std::string url = request->base_url;
    url += "/api/v1/urls";
    {
      std::string query;
      if (!urls_make_query_string(request, &query)) {
        response->logs += "The query string contains invalid arguments.\n";
        return response.release();
      }
      url += query;
    }
    std::swap(curl_request.url, url);
  }
  mk::curl::Response curl_response = mk::curl::perform(curl_request);
  for (auto &log : curl_response.logs) {
    response->logs += log.line;
    response->logs += "\n";
  }
  if (curl_response.error != 0) {
    return response.release();
  }
  if (curl_response.status_code != 200) {
    return response.release();
  }
  {
    std::string body = std::move(curl_response.body);
    response->logs += "Response body: ";
    response->logs += body;
    response->logs += "\n";
    try {
      nlohmann::json doc = nlohmann::json::parse(body);
      response->metadata.count = doc.at("metadata").at("count");
      response->metadata.current_page = doc.at("metadata").at("current_page");
      response->metadata.limit = doc.at("metadata").at("limit");
      response->metadata.next_url = doc.at("metadata").at("next_url");
      response->metadata.pages = doc.at("metadata").at("pages");
      for (auto entry : doc.at("results")) {
        mkorchestra_urls_result_entry result;
        result.category_code = entry.at("category_code");
        result.country_code = entry.at("country_code");
        result.url = entry.at("url");
        response->results.push_back(std::move(result));
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

void mkorchestra_urls_request_delete(mkorchestra_urls_request_t *request) {
  delete request;
}

int64_t mkorchestra_urls_response_good(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->good;
}

int64_t mkorchestra_urls_response_get_metadata_count(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->metadata.count;
}

int64_t mkorchestra_urls_response_get_metadata_current_page(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->metadata.current_page;
}

int64_t mkorchestra_urls_response_get_metadata_limit(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->metadata.limit;
}

const char *mkorchestra_urls_response_get_metadata_next_url(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->metadata.next_url.c_str();
}

int64_t mkorchestra_urls_response_get_metadata_pages(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->metadata.pages;
}

size_t mkorchestra_urls_response_get_results_size(
    const mkorchestra_urls_response_t *response) {
  if (response == nullptr) {
    abort();
  }
  return response->results.size();
}

const char *mkorchestra_urls_response_get_result_category_code_at(
    const mkorchestra_urls_response_t *response, size_t idx) {
  if (response == nullptr || idx >= response->results.size()) {
    abort();
  }
  return response->results[idx].category_code.c_str();
}

const char *mkorchestra_urls_response_get_result_country_code_at(
    const mkorchestra_urls_response_t *response, size_t idx) {
  if (response == nullptr || idx >= response->results.size()) {
    abort();
  }
  return response->results[idx].country_code.c_str();
}

const char *mkorchestra_urls_response_get_result_url_at(
    const mkorchestra_urls_response_t *response, size_t idx) {
  if (response == nullptr || idx >= response->results.size()) {
    abort();
  }
  return response->results[idx].url.c_str();
}

void mkorchestra_urls_response_get_binary_logs(
    const mkorchestra_urls_response_t *response,
    const uint8_t **data, size_t *count) {
  if (response == nullptr || data == nullptr || count == nullptr) {
    abort();
  }
  *data = (const uint8_t *)response->logs.c_str();
  *count = response->logs.size();
}

void mkorchestra_urls_response_delete(
    mkorchestra_urls_response_t *response) {
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

std::string mkorchestra_testhelpers_response_moveout_logs(
    mkorchestra_testhelpers_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

std::string mkorchestra_urls_response_moveout_logs(
    mkorchestra_urls_response_uptr &response) {
  if (response == nullptr) {
    abort();
  }
  return std::move(response->logs);
}

#endif  // MKORCHESTRA_INLINE_IMPL
#endif  // __cplusplus
#endif  // MEASUREMENT_KIT_MKORCHESTRA_H
