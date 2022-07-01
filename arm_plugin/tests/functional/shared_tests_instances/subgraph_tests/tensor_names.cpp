// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "subgraph_tests/tensor_names.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace SubgraphTestsDefinitions;

namespace {
    INSTANTIATE_TEST_CASE_P(smoke_Check, TensorNamesTest,
                            ::testing::Values(CommonTestUtils::DEVICE_CPU),
                            TensorNamesTest::getTestCaseName);
}  // namespace
