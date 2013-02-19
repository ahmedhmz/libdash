/*
 * RepresentationHelper.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "RepresentationHelper.h"

using namespace dash::mpd;
using namespace libdash::framework::mpd;

ISegment*   RepresentationHelper::GetInitSegment    (IRepresentation *representation, const std::vector<IBaseUrl *>& baseurls)
{
    /* Check for segment base */
    if(representation->GetSegmentBase())
        return representation->GetSegmentBase()->GetInitialization()->ToSegment(baseurls);

    /* Check for segment template */
    if(representation->GetSegmentTemplate())
        return representation->GetSegmentTemplate()->ToInitializationSegment(baseurls, "", 0);

    return NULL;
}
ISegment*   RepresentationHelper::GetSegment        (IRepresentation *representation, const std::vector<IBaseUrl *>& baseurls, uint32_t number)
{
    /* Check for segment list */
    if(representation->GetSegmentList())
        return representation->GetSegmentList()->GetSegmentURLs().at(number)->ToMediaSegment(baseurls);

    /* Check for segment template */
    if(representation->GetSegmentTemplate())
        return representation->GetSegmentTemplate()->GetMediaSegmentFromNumber(baseurls, "", 0, representation->GetSegmentTemplate()->GetStartNumber() + number);

    return NULL;
}
uint32_t    RepresentationHelper::GetSize           (IRepresentation *representation)
{
    if(representation->GetSegmentList())
        return representation->GetSegmentList()->GetSegmentURLs().size();

    return UINT32_MAX - 1;
}
