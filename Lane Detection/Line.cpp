#pragma once

#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include "Line.h"

Line::Line()
{
	m_x1 = 0;
	m_y1 = 0;
	m_x2 = 0;
	m_y2 = 0;
	m_slope = 0;
	m_bias = 0;
}

Line::Line(int x1, int y1, int x2, int y2) :
	m_x1(x1),
	m_y1(y1),
	m_x2(x2),
	m_y2(y2) 
{
	m_slope = ((float)y2 - (float)y1) / ((float)x2 - (float)x1);
	m_bias = (float)y1 - m_slope * (float)x1;
}

void Line::draw(cv::Mat& image)
{
	line(image, cv::Point(m_x1, m_y1), cv::Point(m_x2, m_y2), cv::Scalar(0, 0, 255), 3, 8);
}

float Line::slope()
{
	return m_slope;
}

float Line::bias()
{
	return m_bias;
}


int Line::x1()
{
	return m_x1;
}

int Line::x2()
{
	return m_x2;
}

int Line::y1()
{
	return m_y1;
}

int Line::y2()
{
	return m_y2;
}