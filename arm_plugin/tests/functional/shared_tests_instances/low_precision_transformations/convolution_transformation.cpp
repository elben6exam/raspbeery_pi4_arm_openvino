// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "low_precision_transformations/convolution_transformation.hpp"
#include "low_precision_transformations/convolution_with_incorrect_weights.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;

namespace {
const std::vector<ngraph::element::Type> netPrecisions = {
    ngraph::element::f32,
    // ngraph::element::f16
};

const std::vector<ngraph::pass::low_precision::LayerTransformation::Params> transformationParamValues = {
    LayerTestsUtils::LayerTransformationParamsNGraphFactory::createParams().setUpdatePrecisions(true),
    LayerTestsUtils::LayerTransformationParamsNGraphFactory::createParams().setUpdatePrecisions(false),
};

const std::vector<LayerTestsDefinitions::ConvolutionTransformationParam> params = {
    // // failed
    // {
    //     { 256ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
    //     false,
    //     {},
    //     false,
    // },
    {
        {},
        false,
        { 255ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -12.7f }, { 12.7f } },
        false,
    },
    // // failed
    // {
    //     { 256ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
    //     false,
    //     { 255ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -12.7f }, { 12.7f } },
    //     false,
    // },
    // // failed
    // {
    //     { 256ul, ngraph::Shape {}, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
    //     false,
    //     { 255ul, ngraph::Shape {}, { 0.f }, { 254.f }, { -12.7f }, { 12.7f } },
    //     false,
    // },
    {
        { 14ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
        false,
        { 14ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -12.7f }, { 12.7f } },
        false,
    },
    {
        { 14ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 25.5f }, { 0.f }, { 25.5f } },
        false,
        { 255ul, ngraph::Shape { 1, 1, 1, 1 }, { -12.7f }, { 12.7f }, { -12.7f }, { 12.7f } },
        false,
    },
    // // failed
    // {
    //     { 256ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
    //     false,
    //     { 16ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -12.7f }, { 12.7f } },
    //     false,
    // },
    // // failed
    // {
    //     { 256ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { -12.7f }, { 12.8f } },
    //     true,
    //     { 255ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -12.7f }, { 12.7f } },
    //     false,
    // },
    // // failed
    // {
    //     { 256ul, ngraph::Shape { 1 }, { 0.f }, { 255.f }, { -18.7f }, { 18.8f } },
    //     true,
    //     { 255ul, ngraph::Shape { 1 }, { 0.f }, { 254.f }, { -18.7f }, { 18.7f } },
    //     false,
    // },
};

const std::vector<ngraph::Shape> shapes = {
    { 1, 3, 16, 16 },
    { 4, 3, 16, 16 }
};

INSTANTIATE_TEST_CASE_P(smoke_LPT, ConvolutionTransformation,
    ::testing::Combine(
        ::testing::ValuesIn(netPrecisions),
        ::testing::ValuesIn(shapes),
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::ValuesIn(transformationParamValues),
        ::testing::ValuesIn(params)),
    ConvolutionTransformation::getTestCaseName);

const std::vector<LayerTestsDefinitions::ConvolutionWIthIncorrectWeightsParam> incorrectWeightsParams = {
    // incorrect weights
    {
        { 256ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
        { 255ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -127.f }, { 127.f } },
        false
    },
    // correct weights
    {
        { 256ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 255.f }, { 0.f }, { 25.5f } },
        { 255ul, ngraph::Shape { 1, 1, 1, 1 }, { 0.f }, { 254.f }, { -127.f }, { 127.f } },
        true
    }
};

INSTANTIATE_TEST_CASE_P(smoke_LPT, ConvolutionWIthIncorrectWeightsTransformation,
    ::testing::Combine(
        ::testing::ValuesIn(netPrecisions),
        ::testing::Values(ngraph::Shape({ 1, 3, 16, 16 })),
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::ValuesIn(transformationParamValues),
        ::testing::ValuesIn(incorrectWeightsParams)),
    ConvolutionWIthIncorrectWeightsTransformation::getTestCaseName);
}  // namespace
