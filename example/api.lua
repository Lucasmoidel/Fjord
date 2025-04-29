-- api.lua
---@class Vector2
---@field x number
---@field y number
local Vector2 = { x = 0, y = 0 }

---@class Transform
---@field position Vector2
local Transform = { position = Vector2 }

---@class Node
---@field transform Transform
local Node = { transform = Transform }

return {
    Node = Node,
    Vector2 = Vector2,
    Transform = Transform,
}
