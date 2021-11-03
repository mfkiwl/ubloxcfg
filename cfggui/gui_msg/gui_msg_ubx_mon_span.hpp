/* ************************************************************************************************/ // clang-format off
// flipflip's cfggui
//
// Copyright (c) 2021 Philippe Kehl (flipflip at oinkzwurgl dot org),
// https://oinkzwurgl.org/hacking/ubloxcfg
//
// This program is free software: you can redistribute it and/or modify it under the terms of the
// GNU General Public License as published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef __GUI_MSG_UBX_MON_SPAN_H__
#define __GUI_MSG_UBX_MON_SPAN_H__

#include <memory>

#include "imgui.h"
#include "gui_msg.hpp"

/* ***** UBX-MON-SPAN renderer ************************************************************************************** */

class GuiMsgUbxMonSpan : public GuiMsg
{
    public:
        GuiMsgUbxMonSpan(std::shared_ptr<Receiver> receiver = nullptr, std::shared_ptr<Logfile> logfile = nullptr);

        void Update(const std::shared_ptr<Ff::ParserMsg> &msg) final;
        bool Render(const std::shared_ptr<Ff::ParserMsg> &msg, const ImVec2 &sizeAvail) final;
        void Clear() final;

    protected:

        struct SpectData
        {
            SpectData();
            bool valid;
            std::vector<double> freq;
            std::vector<double> ampl;
            std::vector<double> min;
            std::vector<double> max;
            std::vector<double> mean;
            double center;
            double span;
            double res;
            double pga;
            double count;
        };
        struct Label
        {
            Label(const double _freq, const char *_label);
            double      freq;
            std::string title;
            std::string id;
        };

        std::vector<SpectData> _spects;
        ImPlotFlags          _plotFlags;
        std::vector<Label>   _labels;
        bool                 _resetPlotRange;

    private:
};

/* ****************************************************************************************************************** */
#endif // __GUI_MSG_UBX_MON_SPAN_H__
