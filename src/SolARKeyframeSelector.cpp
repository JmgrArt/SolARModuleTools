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

#include "SolARKeyframeSelector.h"

namespace xpcf  = org::bcom::xpcf;

XPCF_DEFINE_FACTORY_CREATE_INSTANCE(SolAR::MODULES::TOOLS::SolARKeyframeSelector);

namespace SolAR {
using namespace datastructure;
namespace MODULES {
namespace TOOLS {

SolARKeyframeSelector::SolARKeyframeSelector():ConfigurableBase(xpcf::toUUID<SolARKeyframeSelector>())
{
   addInterface<api::solver::map::IKeyframeSelector>(this);
   SRef<xpcf::IPropertyMap> params = getPropertyRootNode();
   params->wrapInteger("minNbMatchesIsKeyframe", m_minNbMatchesIsKeyframe);
   params->wrapFloat("minMeanDistanceIsKeyframe", m_minMeanDistanceIsKeyframe);
}


bool SolARKeyframeSelector::select(const SRef<Frame> frame, const std::vector<DescriptorMatch>& matches)
{
    if (matches.size() < m_minNbMatchesIsKeyframe)
        return false;

    std::vector<SRef<Keypoint>> keypointsCurrent, keypointsRef;

    if (frame->getReferenceKeyframe() == nullptr)
        return false;

    keypointsCurrent = frame->getKeypoints();
    keypointsRef = frame->getReferenceKeyframe()->getKeypoints();

    unsigned int imageWidth = frame->getView()->getWidth();

    double totalMatchesDist = 0.0;
    for (int i = 0; i < matches.size(); i++)
    {
        SRef<Keypoint> keypointRef = keypointsRef[matches[i].getIndexInDescriptorA()];
        SRef<Keypoint> keypointCurrent = keypointsCurrent[matches[i].getIndexInDescriptorB()];

        totalMatchesDist+=((*keypointRef)-(*keypointCurrent)).norm()/imageWidth;
    }
    return (totalMatchesDist/matches.size()>m_minMeanDistanceIsKeyframe);
}

}
}
}
