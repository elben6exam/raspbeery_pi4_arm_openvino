// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "common_test_utils/test_constants.hpp"
#include "single_layer_tests/group_convolution_backprop_data.hpp"

using namespace LayerTestsDefinitions;

namespace {

const std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16
};

const std::vector<size_t> numOutChannels = {16, 32};
const std::vector<size_t> numGroups = {2, 8, 16};

/* ============= 1D GroupConvolution ============= */
const std::vector<std::vector<size_t >> inputShapes1D = {{1, 16, 32}};

const std::vector<std::vector<size_t >> kernels1D = {{1}, {3}};
const std::vector<std::vector<size_t>> strides1D = {{1}};
const std::vector<std::vector<ptrdiff_t>> padBegins1D = {{0}};
const std::vector<std::vector<ptrdiff_t>> padEnds1D = {{0}};
const std::vector<std::vector<size_t>> dilations1D = {{1}};

const auto groupConvBackpropData1DParams_ExplicitPadding = ::testing::Combine(
        ::testing::ValuesIn(kernels1D),
        ::testing::ValuesIn(strides1D),
        ::testing::ValuesIn(padBegins1D),
        ::testing::ValuesIn(padEnds1D),
        ::testing::ValuesIn(dilations1D),
        ::testing::ValuesIn(numOutChannels),
        ::testing::ValuesIn(numGroups),
        ::testing::Values(ngraph::op::PadType::EXPLICIT)
);

const auto groupConvBackpropData1DParams_AutoPadValid = ::testing::Combine(
        ::testing::ValuesIn(kernels1D),
        ::testing::ValuesIn(strides1D),
        ::testing::ValuesIn(padBegins1D),
        ::testing::ValuesIn(padEnds1D),
        ::testing::ValuesIn(dilations1D),
        ::testing::ValuesIn(numOutChannels),
        ::testing::ValuesIn(numGroups),
        ::testing::Values(ngraph::op::PadType::VALID)
);

INSTANTIATE_TEST_CASE_P(smoke_GroupConvBackpropData1D_ExplicitPadding, GroupConvBackpropDataLayerTest,
                        ::testing::Combine(
                                groupConvBackpropData1DParams_ExplicitPadding,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::ValuesIn(inputShapes1D),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        GroupConvBackpropDataLayerTest::getTestCaseName);

INSTANTIATE_TEST_CASE_P(smoke_GroupConvBackpropData1D_AutoPadValid, GroupConvBackpropDataLayerTest,
                        ::testing::Combine(
                                groupConvBackpropData1DParams_AutoPadValid,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::ValuesIn(inputShapes1D),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        GroupConvBackpropDataLayerTest::getTestCaseName);

/* ============= 2D GroupConvolution ============= */
const std::vector<std::vector<size_t >> inputShapes2D = {{1, 16, 10, 10},
                                                         {1, 32, 10, 10}};
const std::vector<std::vector<size_t >> kernels2D = {{1, 1}, {3, 3}};
const std::vector<std::vector<size_t >> strides2D = {{1, 1}};
const std::vector<std::vector<ptrdiff_t>> padBegins2D = {{0, 0}};
const std::vector<std::vector<ptrdiff_t>> padEnds2D = {{0, 0}};
const std::vector<std::vector<size_t >> dilations2D = {{1, 1}};

const auto groupConvBackpropData2DParams_ExplicitPadding = ::testing::Combine(
        ::testing::ValuesIn(kernels2D),
        ::testing::ValuesIn(strides2D),
        ::testing::ValuesIn(padBegins2D),
        ::testing::ValuesIn(padEnds2D),
        ::testing::ValuesIn(dilations2D),
        ::testing::ValuesIn(numOutChannels),
        ::testing::ValuesIn(numGroups),
        ::testing::Values(ngraph::op::PadType::EXPLICIT)
);
const auto groupConvBackpropData2DParams_AutoPadValid = ::testing::Combine(
        ::testing::ValuesIn(kernels2D),
        ::testing::ValuesIn(strides2D),
        ::testing::ValuesIn(padBegins2D),
        ::testing::ValuesIn(padEnds2D),
        ::testing::ValuesIn(dilations2D),
        ::testing::ValuesIn(numOutChannels),
        ::testing::ValuesIn(numGroups),
        ::testing::Values(ngraph::op::PadType::VALID)
);

INSTANTIATE_TEST_CASE_P(smoke_GroupConvBackpropData2D_ExplicitPadding, GroupConvBackpropDataLayerTest,
                        ::testing::Combine(
                                groupConvBackpropData2DParams_ExplicitPadding,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::ValuesIn(inputShapes2D),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        GroupConvBackpropDataLayerTest::getTestCaseName);

INSTANTIATE_TEST_CASE_P(smoke_GroupConvBackpropData2D_AutoPadValid, GroupConvBackpropDataLayerTest,
                        ::testing::Combine(
                                groupConvBackpropData2DParams_AutoPadValid,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::ValuesIn(inputShapes2D),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        GroupConvBackpropDataLayerTest::getTestCaseName);

/* ============= 3D GroupConvolution ============= */
const std::vector<std::vector<size_t >> inputShapes3D = {{1, 16, 5, 5, 5},
                                                         {1, 32, 5, 5, 5}};
const std::vector<std::vector<size_t >> kernels3D = {{1, 1, 1}, {3, 3, 3}};
const std::vector<std::vector<size_t >> strides3D = {{1, 1, 1}};
const std::vector<std::vector<ptrdiff_t>> padBegins3D = {{0, 0, 0}};
const std::vector<std::vector<ptrdiff_t>> padEnds3D = {{0, 0, 0}};
const std::vector<std::vector<size_t >> dilations3D = {{1, 1, 1}};

const auto groupConvBackpropData3DParams_ExplicitPadding = ::testing::Combine(
        ::testing::ValuesIn(kernels3D),
        ::testing::ValuesIn(strides3D),
        ::testing::ValuesIn(padBegins3D),
        ::testing::ValuesIn(padEnds3D),
        ::testing::ValuesIn(dilations3D),
        ::testing::ValuesIn(numOutChannels),
        ::testing::ValuesIn(numGroups),
        ::testing::Values(ngraph::op::PadType::EXPLICIT)
);
const auto groupConvBackpropData3DParams_AutoPadValid = ::testing::Combine(
        ::testing::ValuesIn(kernels3D),
        ::testing::ValuesIn(strides3D),
        ::testing::ValuesIn(padBegins3D),
        ::testing::ValuesIn(padEnds3D),
        ::testing::ValuesIn(dilations3D),
        ::testing::ValuesIn(numOutChannels),
        ::testing::ValuesIn(numGroups),
        ::testing::Values(ngraph::op::PadType::VALID)
);

INSTANTIATE_TEST_CASE_P(smoke_GroupConvBackpropData3D_ExplicitPadding, GroupConvBackpropDataLayerTest,
                        ::testing::Combine(
                                groupConvBackpropData3DParams_ExplicitPadding,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::ValuesIn(inputShapes3D),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        GroupConvBackpropDataLayerTest::getTestCaseName);

INSTANTIATE_TEST_CASE_P(smoke_GroupConvBackpropData3D_AutoPadValid, GroupConvBackpropDataLayerTest,
                        ::testing::Combine(
                                groupConvBackpropData3DParams_AutoPadValid,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::Values(InferenceEngine::Layout::ANY),
                                ::testing::ValuesIn(inputShapes3D),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        GroupConvBackpropDataLayerTest::getTestCaseName);

}  // namespace