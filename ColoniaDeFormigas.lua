-- 1135
-- Esclarecimento: anthils = formigueiros

local calcNivel = function(v)
    if nivel[parent[v]] ~= -1 then
        nivel[v] = nivel[parent[v]] + 1
    else
        nivel[v] = calcNivel(nivel[v])
    end

    return nivel[v]
end

local calcDistance = function(i, f)
    local distance = 0
    while i ~= f do
        if nivel[i] > nivel[f] then
            distance = distance + d_parent[i]
            i = parent[i]
        elseif nivel[i] < nivel[f] then
            distance = distance + d_parent[f]
            f = parent[f]
        else
            distance = distance + d_parent[i] + d_parent[f]
            i = parent[i]
            f = parent[f]
        end
    end
    return distance
end

while true do
    local anthils = tonumber(io.read())

    if anthils == 0 then
        os.exit()
    end
    
    parent = {}
    d_parent = {}
    nivel = {}

    for i = 0, anthils - 1, 1 do
        parent[i] = -1
        d_parent[i] = -1
        nivel[i] = -1
    end
    
    nivel[0] = 0
    parent[0] = 0

    for anthil = 1, anthils - 1, 1 do
        local it = string.gmatch(io.read(), "%w+")
        local parent_anthill = tonumber(it())
        local distance = tonumber(it())
        parent[anthil] = parent_anthill
        d_parent[anthil] = distance
        nivel[anthil] = nivel[parent_anthill] + 1
    end

    local num_queries = tonumber(io.read())
    
    for i = 1, num_queries, 1 do
        local it = string.gmatch(io.read(), "%w+")
        local v1 = tonumber(it())
        local v2 = tonumber(it())
        io.write(calcDistance(v1, v2) .. " ")
    end
end