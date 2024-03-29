--3369 incompleto
-- function do_tables_match( a, b )
--     return table.concat(a) == table.concat(b)
-- end
function is_table_equal(t1,t2,ignore_mt)
    local ty1 = type(t1)
    local ty2 = type(t2)
    if ty1 ~= ty2 then return false end
    -- non-table types can be directly compared
    if ty1 ~= 'table' and ty2 ~= 'table' then return t1 == t2 end
    -- as well as tables which have the metamethod __eq
    local mt = getmetatable(t1)
    if not ignore_mt and mt and mt.__eq then return t1 == t2 end
    for k1,v1 in pairs(t1) do
       local v2 = t2[k1]
       if v2 == nil or not is_table_equal(v1,v2) then return false end
    end
    for k2,v2 in pairs(t2) do
       local v1 = t1[k2]
       if v1 == nil or not is_table_equal(v1,v2) then return false end
    end
    return true
 end

words = {}
initial_letters = {}

a = tonumber(io.read())
for i = 1, a, 1 do
    word = io.read()
    letters = {}
    word:gsub(".", function(c)
        letters[c] = true
    end)
    initial_letters[string.sub(word, 1, 1)] = true
    table.insert(words, letters)
end

for k, word in pairs(words) do
    if is_table_equal(word, initial_letters) then
        io.write("Y")
        os.exit()
    end
end

io.write("N")