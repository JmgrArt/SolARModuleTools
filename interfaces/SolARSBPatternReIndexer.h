/**
 * @copyright Copyright (c) 2017 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SOLARSBPATTERNREINDEXER_H
#define SOLARSBPATTERNREINDEXER_H

#include "api/features/ISBPatternReIndexer.h"
#include "ComponentBase.h"
#include "SolARToolsAPI.h"

namespace SolAR {
using namespace datastructure;
namespace MODULES {
namespace TOOLS {

class SOLAR_TOOLS_EXPORT_API SolARSBPatternReIndexer : public org::bcom::xpcf::ComponentBase,
        public api::features::ISBPatternReIndexer {
public:
    SolARSBPatternReIndexer();
    ~SolARSBPatternReIndexer() = default;

    void setParameters (const int sbPatternSize) override;

    FrameworkReturnCode reindex(const std::vector<SRef<Contour2Df>>& candidateContours, const std::vector<DescriptorMatch> & matches, std::vector<SRef<Point2Df>>& patternPoints, std::vector<SRef<Point2Df>>& imagePoints) override;

    void unloadComponent () override final;
       
        XPCF_DECLARE_UUID("a2ef5542-029e-4fce-9974-0aea14b29d6f");
};

}
}
}  // end of namespace Solar

#endif // SOLARSBPATTERNREINDEXER_H
