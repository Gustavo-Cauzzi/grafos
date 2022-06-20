local distance = function(x1, x2, y1, y2) return ((x2-x1)^2 + (y2-y1)^2)^(1/2) end

local function prim(adj, numPeople)
    local nodesConnected = {}
    local distances = {}

    for i = 1, numPeople, 1 do
        nodesConnected[i] = 0
        distances[i] = math.huge;
    end

    distances[1] = 0
    
    for i = 1, numPeople, 1 do
        local smallest = math.huge
        local closestGraph = nil

        for j = 1, numPeople, i do
            if nodesConnected[j] == 0 and distances[j] < smallest then
                smallest = distances[j]
                closestGraph = j
            end
        end

        nodesConnected[closestGraph] = 1

        for j = 1, numPeople, 1 do
            if nodesConnected[j] == 0 and adj[closestGraph][j] < distances[j] then
                distances[j] = adj[closestGraph][j]
            end
        end
    end

    local sum = 0
    for i = 1, numPeople, 1 do
        sum = sum + distances[i]
    end
    return sum
end

--------
local testCases = tonumber(io.read("*l"))

for t = 0, testCases, 1 do
    local numPeople = tonumber(io.read("*l"))
    local adj = {}
    local coordx = {}
    local coordy = {}

    for i = 1, numPeople, 1 do
        local it = string.gmatch(io.read("*l"), "[^%s]+")
        coordx[i] = tonumber(it())
        coordy[i] = tonumber(it())
    end 

    for i = 1, numPeople, 1 do
        local row = {}
        for j = 1, numPeople, 1 do
            table.insert(row, distance(coordx[i], coordx[j], coordy[i], coordy[j]))
        end 
        table.insert(adj, row)
    end 

    local result = prim(adj, numPeople)

    io.write(string.format("%.2f\n", result / 100))
end