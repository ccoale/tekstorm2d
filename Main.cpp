#include "graphics/GraphicsAdapter.h"
#include "graphics/GraphicsDevice.h"
#include "IO/ConsoleStream.h"
#include "IO/TextWriter.h"
#include "math/Color4.h"
#include "graphics/Texture.h"
#include "math/Matrix4.h"
#include <D3D11.h>
#include <xnamath.h>

using namespace Tekstorm;
using namespace Graphics;
using namespace IO;
using namespace Core;
using namespace Math;

struct VERTEX
{
	float x, y, z;
	Color4 color;
	float tu, tv;
};

__declspec(align(16))
struct CBInfo
{
	XMMATRIX world;
	XMMATRIX view;
	XMMATRIX proj;
};

int main()
{
	GraphicsDevice *pDevice = new GraphicsDevice();
	VertexBuffer *buffer = VertexBuffer::CreateVertexBuffer(pDevice, sizeof(VERTEX), 3);
	ConstantBuffer *dataBuff = ConstantBuffer::CreateConstantBuffer(pDevice, sizeof(CBInfo));
	std::cout << sizeof(CBInfo) << "\n";
	Texture *tex = new Texture(pDevice);
	tex->LoadFromFile("crate.bmp");
	//__declspec(align(1))
	VERTEX OurVertices[] =
	{
		{0.0f, 0.5f, 0.0f, Color4::White, .5, 1},
		{0.5f, -0.5, 0.0f, Color4::White, 1, 0},
		{-0.5f, -0.5f, 0.0f, Color4::White, 0, 0}
	};
	buffer->Write<VERTEX>(OurVertices, 3);
	srand(GetTickCount());
	MSG msg;
	
	while (true)
	{
		CBInfo info;
		XMVECTOR center;
		info.world = XMMatrixTransformation2D(XMVectorSet(0, 0, 0, 0), 0, XMVectorSet(25, 25, 1, 0), XMVectorSet(0, 0, 0, 0), 0.0f, XMVectorSet(0, 0, 0, 0));
		info.view = XMMatrixLookAtLH(XMVectorSet(0, 1, -5.0f, 0), XMVectorSet(0, 1, 0, 0), XMVectorSet(0, 1, 0, 0));
		info.proj = ::XMMatrixOrthographicOffCenterLH(0, 800, 600, 0, 0, 1);
		dataBuff->Update(&info);

		pDevice->ProcessEvents(&msg);
		if (msg.message == TEKMSG_EXIT) break;
		pDevice->Clear(Color4::CornflowerBlue);

		pDevice->SetVertexBuffer(buffer);
		pDevice->BindTexture(TEKBIND_PS, 0, tex);
		pDevice->BindConstantBuffer( TEKBIND_VS, 0, dataBuff);
		pDevice->SetPrimitiveType(TEKPRIMITIVE_TRIANGLELIST);
		pDevice->Draw(3);

		pDevice->Present();
	}

	delete dataBuff;
	delete tex;
	delete buffer;
	delete pDevice;
	return 0;
}