#pragma once
#include "ground.h"

//////////////////////////////////////
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#include <dinput.h>
//////////////////////////////////////

#pragma once

class d3dengine_
{
private:
	HINSTANCE                           g_hInst = NULL;
	HWND                                g_hWnd = NULL;
public:	D3D10_DRIVER_TYPE                   g_driverType = D3D10_DRIVER_TYPE_NULL;
		ID3D10Device*                       g_pd3dDevice = NULL;
		IDXGISwapChain*                     g_pSwapChain = NULL;
		ID3D10RenderTargetView*             g_pRenderTargetView = NULL;
		ID3D10Effect*                       g_pEffect = NULL;
		ID3D10EffectTechnique*              g_pTechnique = NULL;
		ID3D10InputLayout*                  g_pVertexLayout = NULL;
		ID3D10Buffer*                       g_pVertexBuffer = NULL;
		ID3D10Buffer*                       g_pIndexBuffer = NULL;
		ID3D10ShaderResourceView*           g_pTextureRV = NULL;
		ID3D10EffectMatrixVariable*         g_pWorldVariable = NULL;
		ID3D10EffectMatrixVariable*         g_pViewVariable = NULL;
		ID3D10EffectMatrixVariable*         g_pProjectionVariable = NULL;
		ID3D10EffectVectorVariable*         g_pMeshColorVariable = NULL;
		ID3D10EffectShaderResourceVariable* g_pDiffuseVariable = NULL;
		D3DXMATRIX                          g_World;
		D3DXMATRIX                          g_View;
		D3DXMATRIX                          g_Projection;
		D3DXVECTOR4                         g_vMeshColor;


		///////////////////////////////////
		IDirectInputDevice8* DIKeyboard;

		LPDIRECTINPUT8 DirectInput;

		char currentKey;

		bool InitDirectInput(HINSTANCE hInstance);
		void DetectInput();

		HRESULT hr;
		///////////////////////////////////

		HRESULT InitDevice();
		d3dengine_(HWND hwnd, HINSTANCE hInst)
		{
			g_hWnd = hwnd;
			g_hInst = hInst;
			g_vMeshColor = D3DXVECTOR4(0.7f, 0.7f, 0.7f, 1.0f);
			InitDevice();
		}
		void CleanupDevice();
};
