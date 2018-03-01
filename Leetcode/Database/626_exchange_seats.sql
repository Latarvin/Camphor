update seat 
set student = (
    case id
    when 2 then (select student from seat where id == 4)
    when 4 then (select student from seat where id == 2)
    end
)