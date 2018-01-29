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

#ifndef SOLAR2DTRANSFORM_H
#define SOLAR2DTRANSFORM_H

#include "api/geom/I2DTransform.h"
#include "ComponentBase.h"
#include "SolARToolsAPI.h"

#include <vector>

namespace SolAR {
using namespace datastructure;
namespace MODULES {
namespace TOOLS {

class SOLAR_TOOLS_EXPORT_API SolAR2DTransform : public org::bcom::xpcf::ComponentBase,
        public api::geom::I2DTransform {
public:

    SolAR2DTransform();
   ~SolAR2DTransform();

    FrameworkReturnCode transform(const std::vector<SRef<Point2Df>> & inputPoints, const Transform2Df transformation, std::vector<SRef<Point2Df>> & outputPoints);

    void unloadComponent () override final;

    XPCF_DECLARE_UUID("edcedc0a-9841-4377-aea1-9fa9fdb46fde");

 private:


};

}
}
}

#endif // SOLAR2DTRANSFORM_H
