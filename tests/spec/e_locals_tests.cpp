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

BACKEND_TEST_CASE( "Testing wasm <e_locals_0_wasm>", "[e_locals_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_locals.0.wasm");
   backend_t bkend( code, &wa );
   CHECK(bkend.call_with_return("env", "local-zero-init")->to_ui64() == UINT32_C(0));
}

BACKEND_TEST_CASE( "Testing wasm <e_locals_1_wasm>", "[e_locals_1_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_locals.1.wasm");
   backend_t bkend( code, &wa );
}

BACKEND_TEST_CASE( "Testing wasm <e_locals_2_wasm>", "[e_locals_2_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_locals.2.wasm");
   CHECK_THROWS_AS(backend_t(code, nullptr), std::exception);
}

BACKEND_TEST_CASE( "Testing wasm <e_locals_3_wasm>", "[e_locals_3_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_locals.3.wasm");
   CHECK_THROWS_AS(backend_t(code, nullptr), std::exception);
}
