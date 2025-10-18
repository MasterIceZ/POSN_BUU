def flood_fill_detection(mask, min_size=1000):
  # ... sample code for flood fill detection ...
  h = mask.shape[0]
  w = mask.shape[1]
  object_id = 0
  objects = {}
  for y in range(0, h, 10):
    for x in range(0, w, 10):
      if mask[y, x] == 255:
        color = get_new_color() # O(1)
        area = fill_area_equals(y, x, mask, color) # O(hw)
        if area >= min_size:
          objects[object_id] = create_new_object(object_id, color) # O(1)
  return objects