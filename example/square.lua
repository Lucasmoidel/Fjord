function Init()
    print("Hello World!")
    ---transform.position.x = 10  -- Line 2: Error here, transform is nil
end

local direction = -1

function Update(dt)
    transform.position.x = transform.position.x + dt * direction
    if transform.position.x > 2 then
        direction = -1
    elseif transform.position.x < -2 then
        direction = 1
    end
    transform.rotation = transform.rotation + 50 * dt
    print("Position: " .. tostring(transform.position.x))

    color.a = 0.5

end