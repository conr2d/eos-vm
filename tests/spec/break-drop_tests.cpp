#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <catch2/catch.hpp>
#include <utils.hpp>
#include <wasm_config.hpp>
#include <eosio/vm/backend.hpp>

using namespace eosio;
using namespace eosio::vm;
extern wasm_allocator wa;

BACKEND_TEST_CASE( "Testing wasm <break-drop_0_wasm>", "[break-drop_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "break-drop.0.wasm");
   backend_t bkend( code, &wa );
   CHECK(!bkend.call_with_return("env", "br"));
   CHECK(!bkend.call_with_return("env", "br_if"));
   CHECK(!bkend.call_with_return("env", "br_table"));
}
