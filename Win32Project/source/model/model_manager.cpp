//=============================================================================
//
// model_manager.cpp
// Author : shota fukuoka
//
//=============================================================================
#include "model_manager.h"
#include "model.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************

///////////////////////////////////////////////////////////////////////////////
//�ǉ�
///////////////////////////////////////////////////////////////////////////////
void ModelManager::AddSkinMeshModel(SkinMeshModel* model)
{
	m_SkinMeshList.push_back(model);
}

///////////////////////////////////////////////////////////////////////////////
//���f���f�[�^�T��
///////////////////////////////////////////////////////////////////////////////
SkinMeshModel *ModelManager::SeekSkinMeshModel(SkinMeshModel* model)
{
	for (auto ite = m_SkinMeshList.begin(); ite != m_SkinMeshList.end(); ++ite)
	{
		if ((*ite)->GetFileName() == model->GetFileName())
		{
			return dynamic_cast<SkinMeshModel*>(*ite);
		}
	}
	model->LoadFile(model->GetFileName());
	AddSkinMeshModel(model);
	return  model;
}

///////////////////////////////////////////////////////////////////////////////
//�X�L�����b�V���폜
///////////////////////////////////////////////////////////////////////////////
void ModelManager::ReleasekSkinMeshModel(void)
{
	for (auto ite = m_SkinMeshList.begin(); ite != m_SkinMeshList.end(); ++ite)
	{
		if ((*ite) == NULL) { continue; }
		(*ite)->Release();
	}
}

///////////////////////////////////////////////////////////////////////////////
//�S�폜
///////////////////////////////////////////////////////////////////////////////
void ModelManager::ReleaseAll(void)
{
	ReleasekSkinMeshModel();
}