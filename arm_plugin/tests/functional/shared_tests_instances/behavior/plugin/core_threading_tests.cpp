// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <behavior/plugin/core_threading.hpp>

namespace {

const Params params[] = {
    std::tuple<Device, Config> { CommonTestUtils::DEVICE_CPU, { { CONFIG_KEY(PERF_COUNT), CONFIG_VALUE(YES) } } },
//   std::tuple<Device, Config> { CommonTestUtils::DEVICE_HETERO, { { "TARGET_FALLBACK", CommonTestUtils::DEVICE_CPU } } },
//   std::tuple<Device, Config> { CommonTestUtils::DEVICE_MULTI, { { MULTI_CONFIG_KEY(DEVICE_PRIORITIES) , CommonTestUtils::DEVICE_CPU } } }
};

const Params paramsStreams[] = {
    std::tuple<Device, Config> { CommonTestUtils::DEVICE_CPU, { { CONFIG_KEY(CPU_THROUGHPUT_STREAMS), CONFIG_VALUE(CPU_THROUGHPUT_AUTO) } } }
};


}  // namespace

INSTANTIATE_TEST_CASE_P(smoke_BehaviorTests, CoreThreadingTests, testing::ValuesIn(params), CoreThreadingTests::getTestCaseName);

INSTANTIATE_TEST_CASE_P(DISABLED_smoke_BehaviorTests, CoreThreadingTestsWithIterations,
    testing::Combine(testing::ValuesIn(params),
                     testing::Values(4),
                     testing::Values(50),
                     testing::Values(ModelClass::Default)),
    CoreThreadingTestsWithIterations::getTestCaseName);

INSTANTIATE_TEST_CASE_P(DISABLED_smoke_Streams_BehaviorTests, CoreThreadingTestsWithIterations,
    testing::Combine(testing::ValuesIn(paramsStreams),
                     testing::Values(4),
                     testing::Values(10),
                     testing::Values(ModelClass::Default)),
    CoreThreadingTestsWithIterations::getTestCaseName);
