    CWSTR c_Cloud2TxtrName                             = L"/data/textures/earth/cloud/cloud_1024_2.dds"; //Cloud shadows

    // Create cloud shadow
    // OBM
    m_pCloud2Model = g_Joshua.Renderer()->Create_Model();
    m_pCloud2Mesh = g_Joshua.Renderer()->CreateMesh();
    m_pCloud2Transform = g_Joshua.Renderer()->Create_Transform_SRT();
    m_pCloud2Material = g_Joshua.Renderer()->Helper()->CreateCompleteMaterial(GFX::VSTYPE_DEF_LIGHT, GFX::PSTYPE_DEF_SIMPLE_TXTR);
    m_pCloud2Texture = g_Joshua.Renderer()->Helper()->LoadTexture(c_Cloud2TxtrName);

    // Initialize cloud shadow model
    // OBM
    m_pRealisticOverlayModel->Add_Child(m_pCloud2Model);
    m_pCloud2Model->Set_Material(m_pCloud2Material);
    m_pCloud2Model->Set_Transform(m_pCloudTransform);
    m_pCloud2Model->Set_Primitive(m_pCloud2Mesh);

     // Initialize cloud shadow material
     // OBM
      GFX::GDefaultVertexShader* l_pCloud2VS = (GFX::GDefaultVertexShader*) m_pCloud2Material->VertexShader(0);
      l_pCloud2VS->Set_Animated();
      l_pCloud2VS->Ambient().R = 0.f;
      l_pCloud2VS->Ambient().G = 0.f;
      l_pCloud2VS->Ambient().B = 0.f;
      l_pCloud2VS->Ambient().A = 0.f;

      GFX::GRenderStateCollection* l_pRenderStatesShadow = m_pCloud2Material->RenderStates(0);
      l_pRenderStatesShadow->Value(GFX::RSTATE_ZBUFFER_WRITE_ENABLE) = false;
      l_pRenderStatesShadow->Value(GFX::RSTATE_ZBUFFER_ENABLE) = false;
      l_pRenderStatesShadow->Value(GFX::RSTATE_ALPHA_BLEND_ENABLE) = true;
      l_pRenderStatesShadow->Value(GFX::RSTATE_ALPHA_SOURCE_BLEND) = GFX::BLEND_SRCALPHA;
      l_pRenderStatesShadow->Value(GFX::RSTATE_ALPHA_DEST_BLEND) = GFX::BLEND_INVSRCALPHA;

      l_pRenderStatesShadow->Value(GFX::RSTATE_ALPHA_TEST_ENABLE) = false;
      l_pRenderStatesShadow->Value(GFX::RSTATE_ALPHA_TEST_REFERENCE) = 16;
      l_pRenderStatesShadow->Value(GFX::RSTATE_ALPHA_TEST_FUNCTION) = GFX::TEST_GREATEREQUAL;

      // Initialize cloud shadow shader
      //OBM
      GFX::GCascadePixelShader* l_pCloud2PS = (GFX::GCascadePixelShader*) m_pCloud2Material->PixelShader(0);
      l_pCloud2PS->TextureSampler(0)->Texture(m_pCloud2Texture);
      l_pCloud2PS->TextureSampler(0)->MagnificationFilter(GFX::FILTER_LINEAR);

      // Initialize cloud shadow mesh
      //OBM
      g_Joshua.Renderer()->Helper()->CreateSphere(m_pCloud2Mesh, 1.f + 1.f / 256.f, 32, 32, HELPER_MESH_CREATE_ALL);
      
      void GBackgroundEarth::CloudsEnable()
{
   if(m_pCloudModel)

      m_pCloudModel->Visibility() = true;
      m_pCloud2Model->Visibility() = true; //OBM
      
      void GBackgroundEarth::CloudsDisable()
{
   if(m_pCloudModel)

      m_pCloudModel->Visibility() = false;
      m_pCloud2Model->Visibility() = false; //OBM
