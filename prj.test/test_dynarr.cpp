#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <dynarr/dynarr.hpp>


TEST_CASE("dynarr ctor") {
    DynArr dynarr(3);

    CHECK(dynarr.Size() == 3);
    CHECK(dynarr.Capacity() == 3);


    DynArr dynarr_s(dynarr);

    CHECK(dynarr_s.Size() == 3);
    CHECK(dynarr_s.Capacity() == 3);


    DynArr dynarr_t{};

    dynarr_t = dynarr;

    CHECK(dynarr_t.Size() == 3);
    CHECK(dynarr_t.Capacity() == 3);

}


TEST_CASE("dynarr resizing") {
    DynArr dynarr{};

    dynarr.Resize(3);

    dynarr.Resize(2);

    CHECK(dynarr.Size() == 2);
    CHECK(dynarr.Capacity() == 3);


    dynarr.Resize(3);

    CHECK(dynarr.Size() == 3);
    CHECK(dynarr.Capacity() == 3);


    dynarr.Resize(2);

    dynarr.Resize(4);

    CHECK(dynarr.Size() == 4);
    CHECK(dynarr.Capacity() == 4);
    CHECK_THROWS(dynarr.Resize(-1));
}


TEST_CASE("dynarr indexing") {
    DynArr dynarr(2);

    dynarr[0] = 1.0f;
    dynarr[1] = 2.0f;

    CHECK(dynarr[0] == 1.0f);
    CHECK(dynarr[1] == 2.0f);

    CHECK_THROWS(dynarr[2]);
    CHECK_THROWS(dynarr[-1]);
}