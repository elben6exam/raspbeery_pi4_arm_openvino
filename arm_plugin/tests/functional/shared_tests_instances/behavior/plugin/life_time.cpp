// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "behavior/plugin/life_time.hpp"

using namespace BehaviorTestsDefinitions;
namespace {
    const std::vector<std::vector<int >> orders = {
            // 0 - plugin
            // 1 - executable_network
            // 2 - infer_request
            {0, 1, 2},
            {0, 2, 1},
            {1, 0, 2},
            {1, 2, 0},
            {2, 0, 1},
            {2, 1, 0}
    };

    INSTANTIATE_TEST_CASE_P(smoke_BehaviorTests, HoldersTest,
            ::testing::Combine(
            ::testing::Values(CommonTestUtils::DEVICE_CPU),
            ::testing::ValuesIn(orders)),
            HoldersTest::getTestCaseName);

}  // namespace