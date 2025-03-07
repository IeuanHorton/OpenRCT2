/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../world/Map.h"
#include "GameAction.h"

class MapChangeSizeAction final : public GameActionBase<GameCommand::ChangeMapSize>
{
public:
    MapChangeSizeAction() = default;
    MapChangeSizeAction(const TileCoordsXY& targetSize);
    MapChangeSizeAction(const TileCoordsXY& targetSize, const TileCoordsXY& shift);

    void AcceptParameters(GameActionParameterVisitor& visitor) override;
    uint16_t GetActionFlags() const override;

    void Serialise(DataSerialiser& stream) override;
    GameActions::Result Query() const override;
    GameActions::Result Execute() const override;

private:
    TileCoordsXY _targetSize;
    TileCoordsXY _shift;
};
