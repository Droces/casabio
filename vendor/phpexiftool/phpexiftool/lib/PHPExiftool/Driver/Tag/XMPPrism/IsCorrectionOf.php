<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPPrism;

use PHPExiftool\Driver\AbstractTag;

class IsCorrectionOf extends AbstractTag
{

    protected $Id = 'isCorrectionOf';

    protected $Name = 'IsCorrectionOf';

    protected $FullName = 'XMP::prism';

    protected $GroupName = 'XMP-prism';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-prism';

    protected $g2 = 'Document';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Is Correction Of';

    protected $flag_Avoid = true;

    protected $flag_List = true;

    protected $flag_Bag = true;

}
