#include "StaticLoader.h"

bool Angel_ResourcesLoad(AssetManager& manager, std::string resource_dir) {

	return true;
}

bool Angel_ResourcesScanDirectory(std::string list_path) {

	return true;
}

bool Angel_ResourcesLoadAsset(std::string asset_path, assetType asset_type) {
	switch (asset_type) {
	case SR_SPRITE:
		// Angel_MakeSprite();
		break;
	case SR_FONT:

		break;
	}
	return true;
}