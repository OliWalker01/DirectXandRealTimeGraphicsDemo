////////////////////////////////////////////////////////////////////////////////
// Filename: firemodelclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _FIREMODELCLASS_H_
#define _FIREMODELCLASS_H_

//////////////
// INCLUDES //
//////////////
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <fstream>

using namespace DirectX;
using namespace std;

///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textureclass.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: FireModelClass
////////////////////////////////////////////////////////////////////////////////
class FireModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

public:
	FireModelClass();
	FireModelClass(const FireModelClass&);
	~FireModelClass();

	bool Initialize(ID3D11Device*, char*, WCHAR*, WCHAR*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	ID3D11ShaderResourceView* GetTexture1();
	ID3D11ShaderResourceView* GetTexture2();
	ID3D11ShaderResourceView* GetTexture3();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTextures(ID3D11Device*, WCHAR*, WCHAR*, WCHAR*);
	void ReleaseTextures();

	bool LoadModel(char*);
	void ReleaseModel();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	int m_vertexCount, m_indexCount;
	TextureClass* m_Texture1, * m_Texture2, * m_Texture3;
	ModelType* m_model;
};

#endif