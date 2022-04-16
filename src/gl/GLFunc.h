

#pragma once

class GLTriangleDemo
{
public:
	GLTriangleDemo();
	~GLTriangleDemo();

	// prepare shader paragram
	void buildShader();

	// prepare render data
	void buildRenderData();
	
	// render
	void render();

protected:
	unsigned int _shaderProgram;
	unsigned int _vao, _vbo, _ebo;
};
