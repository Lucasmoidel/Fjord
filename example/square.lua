function Init()
    print("Hello World!")
end

function Update(dt)
    transform.position.x = transform.position.x + dt * 1
    print("Hello WOrld!", tostring(transform.position))
end