#include <map>
#include <string>
#include <list>

using namespace std;
typedef map<string, string> object;

class Scene
{
    string name;
    string type;
};

class SceneFactory
{
public:
    virtual Scene create(object config) const;
};

class StorySceneFactory : public SceneFactory
{
public:
    Scene create(object config) const;
};

const map<string, SceneFactory*> SCENE_FACTORIES = {
    {"story", new StorySceneFactory()}};

const map<string, Scene> DEFAULT_SCENES = {
    {"simpleEntity", Scene()}};

class SceneLibrary
{
public:
    void add(object config);
    Scene create(string sceneId);
    void debug();

private:
    map<string, Scene> DEFAULT_SCENES;
};
