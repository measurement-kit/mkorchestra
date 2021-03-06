#include "mkorchestra.h"

#include <iostream>

#define MKCURL_INLINE_IMPL
#include "mkcurl.hpp"

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
      r.get(), ".mkbuild/data/cacert.pem");
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
  mkorchestra_login_request_set_ca_bundle_path(r.get(), ".mkbuild/data/cacert.pem");
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
      r.get(), ".mkbuild/data/cacert.pem");
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

static std::string events_baseurl() {
  return "https://events.proteus.test.ooni.io";
}

TEST_CASE("We can get the available collectors") {
  mkorchestra_collectors_request_uptr r{
      mkorchestra_collectors_request_new_nonnull()};
  mkorchestra_collectors_request_set_base_url(
      r.get(), events_baseurl().c_str());
  mkorchestra_collectors_request_set_ca_bundle_path(
      r.get(), ".mkbuild/data/cacert.pem");
  mkorchestra_collectors_request_set_timeout(r.get(), 14);
  mkorchestra_collectors_response_uptr re{
      mkorchestra_collectors_request_perform_nonnull(r.get())};
  {
    std::string logs = mkorchestra_collectors_response_moveout_logs(re);
    REQUIRE(logs.size() > 0);
    std::clog << "=== BEGIN COLLECTORS LOGS ===" << std::endl;
    std::clog << logs;
    std::clog << "=== END COLLECTORS LOGS ===" << std::endl;
  }
  REQUIRE(mkorchestra_collectors_response_good(re.get()));
  size_t n = mkorchestra_collectors_response_get_collectors_size(re.get());
  REQUIRE(n > 0);
  for (size_t i = 0; i < n; ++i) {
    mkorchestra_collector_uptr c;
    c.reset(mkorchestra_collectors_response_get_collector_at(re.get(), i));
    std::clog << "type: "
              << mkorchestra_collector_get_type(c.get())
              << " address: "
              << mkorchestra_collector_get_address(c.get())
              << std::endl;
  }
}

TEST_CASE("We can get the available test-helpers") {
  mkorchestra_testhelpers_request_uptr r{
      mkorchestra_testhelpers_request_new_nonnull()};
  mkorchestra_testhelpers_request_set_base_url(
      r.get(), events_baseurl().c_str());
  mkorchestra_testhelpers_request_set_ca_bundle_path(
      r.get(), ".mkbuild/data/cacert.pem");
  mkorchestra_testhelpers_request_set_timeout(r.get(), 14);
  mkorchestra_testhelpers_response_uptr re{
      mkorchestra_testhelpers_request_perform_nonnull(r.get())};
  {
    std::string logs = mkorchestra_testhelpers_response_moveout_logs(re);
    REQUIRE(logs.size() > 0);
    std::clog << "=== BEGIN TESTHELPERS LOGS ===" << std::endl;
    std::clog << logs;
    std::clog << "=== END TESTHELPERS LOGS ===" << std::endl;
  }
  REQUIRE(mkorchestra_testhelpers_response_good(re.get()));
  size_t n = mkorchestra_testhelpers_response_get_testhelpers_size(re.get());
  REQUIRE(n > 0);
  for (size_t i = 0; i < n; ++i) {
    mkorchestra_testhelper_uptr th;
    th.reset(mkorchestra_testhelpers_response_get_testhelper_at(re.get(), i));
    std::clog << "- name: "
              << mkorchestra_testhelper_get_name(th.get())
              << " type: "
              << mkorchestra_testhelper_get_type(th.get())
              << " address: "
              << mkorchestra_testhelper_get_address(th.get())
              << std::endl;
  }
}

static void get_urls(std::string country_code,
                    std::vector<std::string> category_codes,
                    int64_t limit) {
  mkorchestra_urls_request_uptr r{mkorchestra_urls_request_new_nonnull()};
  mkorchestra_urls_request_set_base_url(r.get(), events_baseurl().c_str());
  mkorchestra_urls_request_set_ca_bundle_path(r.get(), ".mkbuild/data/cacert.pem");
  mkorchestra_urls_request_set_timeout(r.get(), 14);
  if (!country_code.empty()) {
    mkorchestra_urls_request_set_country_code(r.get(), country_code.c_str());
  }
  for (auto &s : category_codes) {
    mkorchestra_urls_request_add_category_code(r.get(), s.c_str());
  }
  if (limit > 0) mkorchestra_urls_request_set_limit(r.get(), limit);
  mkorchestra_urls_response_uptr re{
      mkorchestra_urls_request_perform_nonnull(r.get())};
  {
    std::string logs = mkorchestra_urls_response_moveout_logs(re);
    REQUIRE(logs.size() > 0);
    std::clog << "=== BEGIN URLS LOGS ===" << std::endl;
    std::clog << logs;
    std::clog << "=== END URLS LOGS ===" << std::endl;
  }
  REQUIRE(mkorchestra_urls_response_good(re.get()));
  std::clog << "metadata.count: "
            << mkorchestra_urls_response_get_metadata_count(re.get())
            << std::endl;
  std::clog << "metadata.current_page: "
            << mkorchestra_urls_response_get_metadata_current_page(re.get())
            << std::endl;
  std::clog << "metadata.limit: "
            << mkorchestra_urls_response_get_metadata_limit(re.get())
            << std::endl;
  std::clog << "metadata.next_url: "
            << mkorchestra_urls_response_get_metadata_next_url(re.get())
            << std::endl;
  std::clog << "metadata.pages: "
            << mkorchestra_urls_response_get_metadata_pages(re.get())
            << std::endl;
  size_t n = mkorchestra_urls_response_get_results_size(re.get());
  REQUIRE(n > 0);
  for (size_t i = 0; i < n; ++i) {
    std::clog << "- category_code: "
              << mkorchestra_urls_response_get_result_category_code_at(
									re.get(), i)
              << " country_code: "
              << mkorchestra_urls_response_get_result_country_code_at(
									re.get(), i)
              << " url: "
              << mkorchestra_urls_response_get_result_url_at(
									re.get(), i)
              << std::endl;
  }
}

TEST_CASE("We can get the URLs without query string params") {
	get_urls("", {}, -1);
}

TEST_CASE("We can get the URLs with query string params") {
	get_urls("IT", {"POLR", "HUMR"}, 7);
}
