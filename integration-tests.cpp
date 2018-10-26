#include "mkorchestra.h"

#include <iostream>

#define MKCURL_INLINE_IMPL
#include "mkcurl.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

static mkorchestra_metadata_uptr get_metadata() {
  mkorchestra_metadata_uptr metadata{mkorchestra_metadata_new_nonnull()};
  mkorchestra_metadata_set_available_bandwidth(metadata.get(), "128");
  mkorchestra_metadata_set_language(metadata.get(), "it_IT");
  mkorchestra_metadata_set_network_type(metadata.get(), "wifi");
  mkorchestra_metadata_set_platform(metadata.get(), "macos");
  mkorchestra_metadata_set_probe_asn(metadata.get(), "AS30722");
  mkorchestra_metadata_set_probe_cc(metadata.get(), "IT");
  mkorchestra_metadata_set_software_name(metadata.get(), "mkorchestra");
  mkorchestra_metadata_set_software_version(metadata.get(), "0.1.0");
  mkorchestra_metadata_add_supported_test(metadata.get(), "ndt");
  return metadata;
}

static std::string get_password() { return "fidodido"; }

static std::string register_baseurl() {
  return "https://registry.proteus.test.ooni.io";
}

static std::string register_probe() {
  mkorchestra_register_request_uptr r{
      mkorchestra_register_request_new_nonnull()};
  mkorchestra_register_request_set_password(r.get(), get_password().c_str());
  mkorchestra_register_request_set_metadata(r.get(), get_metadata().get());
  mkorchestra_register_request_set_base_url(
      r.get(), register_baseurl().c_str());
  mkorchestra_register_request_set_ca_bundle_path(
      r.get(), "ca-bundle.pem");
  mkorchestra_register_request_set_timeout(r.get(), 14);
  mkorchestra_register_response_uptr re{
      mkorchestra_register_request_perform_nonnull(r.get())};
  {
    std::string logs = mkorchestra_register_response_moveout_logs(re);
    REQUIRE(logs.size() > 0);
    std::clog << "=== BEGIN REGISTER LOGS ===" << std::endl;
    std::clog << logs;
    std::clog << "=== END REGISTER LOGS ===" << std::endl;
  }
  REQUIRE(mkorchestra_register_response_good(re.get()));
  std::string client_id;
  {
    client_id = mkorchestra_register_response_get_client_id(re.get());
    REQUIRE(client_id.size() > 0);
    std::clog << client_id << std::endl;
  }
  return client_id;
}

TEST_CASE("We can register a new probe") {
  (void)register_probe();
}

static std::string login(std::string client_id) {
  mkorchestra_login_request_uptr r{mkorchestra_login_request_new_nonnull()};
  mkorchestra_login_request_set_username(r.get(), client_id.c_str());
  mkorchestra_login_request_set_password(r.get(), get_password().c_str());
  mkorchestra_login_request_set_base_url(r.get(), register_baseurl().c_str());
  mkorchestra_login_request_set_ca_bundle_path(r.get(), "ca-bundle.pem");
  mkorchestra_login_request_set_timeout(r.get(), 14);
  mkorchestra_login_response_uptr re{
      mkorchestra_login_request_perform_nonnull(r.get())};
  {
    std::string logs = mkorchestra_login_response_moveout_logs(re);
    REQUIRE(logs.size() > 0);
    std::clog << "=== BEGIN LOGIN LOGS ===" << std::endl;
    std::clog << logs;
    std::clog << "=== END LOGIN LOGS ===" << std::endl;
  }
  REQUIRE(mkorchestra_login_response_good(re.get()));
  std::string token;
  {
    token = mkorchestra_login_response_get_token(re.get());
    REQUIRE(token.size() > 0);
    std::clog << token << std::endl;
  }
  {
    std::string expire = mkorchestra_login_response_get_expire(re.get());
    REQUIRE(expire.size() > 0);
    std::clog << expire << std::endl;
  }
  return token;
}

TEST_CASE("We can successfully login") {
  (void)login(register_probe());
}

TEST_CASE("We can successfully update") {
  std::string client_id = register_probe();
  std::string token = login(client_id);
  mkorchestra_update_request_uptr r{
      mkorchestra_update_request_new_nonnull()};
  mkorchestra_update_request_set_client_id(r.get(), client_id.c_str());
  mkorchestra_update_request_set_token(r.get(), token.c_str());
  mkorchestra_update_request_set_metadata(r.get(), get_metadata().get());
  mkorchestra_update_request_set_base_url(
      r.get(), register_baseurl().c_str());
  mkorchestra_update_request_set_ca_bundle_path(
      r.get(), "ca-bundle.pem");
  mkorchestra_update_request_set_timeout(r.get(), 14);
  mkorchestra_update_response_uptr re{
      mkorchestra_update_request_perform_nonnull(r.get())};
  {
    std::string logs = mkorchestra_update_response_moveout_logs(re);
    REQUIRE(logs.size() > 0);
    std::clog << "=== BEGIN UPDATE LOGS ===" << std::endl;
    std::clog << logs;
    std::clog << "=== END UPDATE LOGS ===" << std::endl;
  }
  REQUIRE(mkorchestra_update_response_good(re.get()));
}
