// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>
#include <ngraph/opsets/opset3.hpp>

#include "single_layer_tests/space_to_depth.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;
using namespace ngraph::opset3;

namespace {
const std::vector<InferenceEngine::Precision> inputPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16,
};

const std::vector<SpaceToDepth::SpaceToDepthMode> modes = {
        SpaceToDepth::SpaceToDepthMode::BLOCKS_FIRST,
};

const std::vector<std::vector<size_t >> inputShapesBS2 = {
        {1, 1, 2, 2}, {1, 1, 4, 4}, {1, 1, 6, 6}, {2, 8, 6, 6}, {2, 4, 10, 8},
};

const auto SpaceToDepthBS2 = ::testing::Combine(
        ::testing::ValuesIn(inputShapesBS2),
        ::testing::ValuesIn(inputPrecisions),
        ::testing::ValuesIn(modes),
        ::testing::Values(2),
        ::testing::Values(CommonTestUtils::DEVICE_CPU)
);

INSTANTIATE_TEST_CASE_P(smoke_SpaceToDepthBS2Test, SpaceToDepthLayerTest, SpaceToDepthBS2, SpaceToDepthLayerTest::getTestCaseName);

const std::vector<std::vector<size_t >> inputShapesBS3 = {
        {1, 1, 3, 3}, {1, 1, 6, 6}, {1, 1, 9, 9}, {2, 4, 9, 9}, {2, 3, 15, 12},
};

const auto SpaceToDepthBS3 = ::testing::Combine(
        ::testing::ValuesIn(inputShapesBS3),
        ::testing::ValuesIn(inputPrecisions),
        ::testing::ValuesIn(modes),
        ::testing::Values(3),
        ::testing::Values(CommonTestUtils::DEVICE_CPU)
);

INSTANTIATE_TEST_CASE_P(smoke_SpaceToDepthBS3Test, SpaceToDepthLayerTest, SpaceToDepthBS3, SpaceToDepthLayerTest::getTestCaseName);

}  // namespace