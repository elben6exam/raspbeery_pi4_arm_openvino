// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "single_layer_tests/gather_nd.hpp"

using namespace LayerTestsDefinitions;

namespace {

const std::vector<InferenceEngine::Precision> dPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16,
        InferenceEngine::Precision::I32,
        InferenceEngine::Precision::I64,
        InferenceEngine::Precision::I16,
        InferenceEngine::Precision::U8,
};
const std::vector<InferenceEngine::Precision> iPrecisions = {
        InferenceEngine::Precision::I32,
        InferenceEngine::Precision::I64
};

const auto gatherNDArgsSubset1 = ::testing::Combine(
        ::testing::ValuesIn(std::vector<std::vector<size_t>>(
            {{2, 2}, {2, 3, 4}})),                                // Data shape
        ::testing::ValuesIn(std::vector<std::vector<size_t>>(
            {{2, 1}, {2, 1, 1}})),                                // Indices shape
        ::testing::ValuesIn(std::vector<int>({0, 1}))             // Batch dims
);
INSTANTIATE_TEST_CASE_P(smoke_GatherND2d, GatherNDLayerTest,
                        ::testing::Combine(
                            gatherNDArgsSubset1,
                            ::testing::ValuesIn(dPrecisions),
                            ::testing::ValuesIn(iPrecisions),
                            ::testing::Values(CommonTestUtils::DEVICE_CPU),
                            ::testing::Values<Config>({})),
                        GatherNDLayerTest::getTestCaseName);

const auto gatherNDArgsSubset2 = ::testing::Combine(
        ::testing::ValuesIn(std::vector<std::vector<size_t>>(
            {{15, 12, 20, 15, 2}, {15, 12, 18, 7, 17}})),          // Data shape
        ::testing::ValuesIn(std::vector<std::vector<size_t>>(
            {{15, 12, 2}})),                                       // Indices shape
        ::testing::ValuesIn(std::vector<int>({0, 1, 2}))           // Batch dims
);
INSTANTIATE_TEST_CASE_P(smoke_GatherND, GatherNDLayerTest,
                        ::testing::Combine(
                            gatherNDArgsSubset2,
                            ::testing::ValuesIn(dPrecisions),
                            ::testing::ValuesIn(iPrecisions),
                            ::testing::Values(CommonTestUtils::DEVICE_CPU),
                            ::testing::Values<Config>({})),
                        GatherNDLayerTest::getTestCaseName);
}  // namespace
