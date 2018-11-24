#pragma once
#include <vector>
#include "Scene.hpp"
#include "cbuffer.h"

namespace My {
    struct DrawFrameContext : PerFrameConstants {
        intptr_t globalShadowMap;
        intptr_t shadowMap;
        intptr_t cubeShadowMap;
        uint32_t globalShadowMapCount;
        uint32_t shadowMapCount;
        uint32_t cubeShadowMapCount;
        intptr_t skybox;

        DrawFrameContext ()
        {
            globalShadowMap = -1;
            shadowMap = -1;
            cubeShadowMap = -1;
            globalShadowMapCount = 0;
            shadowMapCount = 0;
            cubeShadowMapCount = 0;
        }
    };

    struct DrawBatchContext : PerBatchConstants {
        uint32_t batchIndex;
        std::shared_ptr<SceneGeometryNode> node;
        material_textures material;

        virtual ~DrawBatchContext() = default;
    };

    struct Frame {
        DrawFrameContext frameContext;
        std::vector<std::shared_ptr<DrawBatchContext>> batchContexts;
    };
}