//
// Created by alpluspluss on 22/9/2024 AD.
//

#ifndef BASEINSTANCE_H
#define BASEINSTANCE_H

#include <string>
#include <vector>
#include "connection.h"

class BaseInstance
{
public:
    std::string Name;
    std::string ClassName;
    std::shared_ptr<BaseInstance> parent = nullptr;
    bool Archivable = true;

    void AddTag(const std::string& tag) noexcept;
    void ClearAllChildren() noexcept;
    void Destroy() noexcept;
    BaseInstance Clone() const noexcept;
    BaseInstance FindFirstAncestor(const std::string& name) const noexcept;
    BaseInstance FindFirstAncestorOfClass(const std::string& className) const noexcept;
    BaseInstance FindFirstAncestorWhichIsA(const std::string& className) const noexcept;
    BaseInstance FindFirstChild(const std::string& name, bool recursive = false) const noexcept;
    BaseInstance FindFirstChildOfClass(const std::string& className) const noexcept;
    BaseInstance FindFirstChildWhichIsA(const std::string& className, bool recursive = false) const noexcept;
    BaseInstance FindFirstDescendant(const std::string& name) const noexcept;
    BaseInstance GetActor() const noexcept;
    BaseInstance GetAttribute(const std::string& attribute) const noexcept;
    Signal GetAttributeChangedSignal(const std::string& attribute) const;
    std::vector<BaseInstance> GetChildren() const noexcept;
    std::vector<BaseInstance> GetDescendants() const noexcept;
    std::string GetFullName() const noexcept;
    Signal GetPropertyChangedSignal(const std::string& property) const;
    std::string GetStyled(const std::string& name) const;
    std::vector<std::string> GetTags() const noexcept;
    bool HasTag(const std::string& tag) const noexcept;
    bool IsA(const std::string& className) const noexcept;
    bool IsAncestorOf(const BaseInstance* descendant) const noexcept;
    bool IsDescendantOf(const BaseInstance* ancestor) const noexcept;
    void RemoveTag(const std::string& tag) noexcept;
    void SetAttribute(const std::string& attribute, const std::string& value) noexcept;
    BaseInstance WaitForChild(const std::string& childName, double timeout = 0) const noexcept;

    Signal AncestryChanged;
    Signal AttributeChanged;
    Signal Changed;
    Signal ChildAdded;
    Signal ChildRemoved;
    Signal DescendantAdded;
    Signal DescendantRemoving;
    Signal Destroying;
};

#endif
