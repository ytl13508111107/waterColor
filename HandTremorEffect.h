﻿#ifndef HANDTREMOREFFECT_H
#define HANDTREMOREFFECT_H

#include <opencv2/opencv.hpp>


class HandTremorEffect
{
public:
	void deal(const cv::Mat &input, cv::Mat &output);
};

#endif